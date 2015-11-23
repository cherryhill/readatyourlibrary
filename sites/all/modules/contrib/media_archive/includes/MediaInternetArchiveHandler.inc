<?php

/**
 * @file
 * Contains MediaInternetArchiveHandler.
 * @TODO: implement Archive.org JSON API.
 * @see: http://archive.org/help/json.php
 */

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaInternetArchiveHandler extends MediaInternetBaseHandler {
  /**
   * Call the Archive.org API to fetch the video information.
   *
   *
   *
   * @return
   *   Array of properties.
   */
  static public function getVideoProperties($id, $refresh = FALSE) {

    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_archive:rawid:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }

    $response = drupal_http_request('http://' . MEDIA_ARCHIVE_BASE_URL . '/embed/' . $id . MEDIA_ARCHIVE_REST_API);
    $data = drupal_json_decode($response->data);

    $ids[$id] = $data;
    cache_set('media_archive:rawid:' . $id, $ids[$id], 'cache_media_xml', media_variable_get('xml_cache_expire', 3600));

    return $data;
  }

  /**
   * Check if an Archive.org video id is valid.
   *
   * This is a bit diffrent from other providers,
   * we also return the file_name on success. (?)
   *
   * @return
   *   string $file_name.
   */
  public function validId($video_id) {
    // TODO.
    return TRUE;
  }

  /**
   * Parse the embed code provided by the user.
   */
  public function parse($embedCode) {
    $scheme = 'archive://';
    preg_match('@archive\.org/details/([^"\& ]+)@i', $embedCode, $matches);
    if (!empty($matches)) {
      $org = self::validId($matches[1]);
      return file_stream_wrapper_uri_normalize('archive://' . $matches[1]);
    }
    return FALSE;
  }

  public function claim($embedCode) {
    if ($this->parse($embedCode)) {
      return TRUE;
    }
  }

  public function getFileObject() {
    $uri = $this->parse($this->embedCode);

    $file = file_uri_to_object($uri, TRUE);

    if (empty($file->fid)) {
// TODO: fix up this with a real human readable filename.
//      $title = $path[1];
//      $file->filename = truncate_utf8($title, 255);
    }

    return $file;
  }

  /**
   * Returns information about the media. See http://video.search.yahoo.com/mrss.
   *
   * @return
   *   If ATOM+MRSS information is available, a SimpleXML element containing
   *   ATOM and MRSS elements, as per those respective specifications.
   *
   * @todo Would be better for the return value to be an array rather than a
   *   SimpleXML element, but media_retrieve_xml() needs to be upgraded to
   *   handle namespaces first.
   * http://archive.org/file/4035623?skin=rss
   */
  public function getMRSS() {
    $uri = media_archive_media_parse($this->embedCode);
    $video_id = arg(1, file_uri_target($uri));
    $rss_url = url('http://gdata.archive.org/feeds/api/videos/' . $video_id, array('query' => array('v' => '2')));
    // @todo Use media_retrieve_xml() once it's upgraded to include elements
    //   from all namespaces, not just the document default namespace.
    $entry = simplexml_load_file($rss_url);
    return $entry;
  }

  /**
   * Returns information about the media. See http://www.oembed.com/.
   *
   * @return
   *   If oEmbed information is available, an array containing 'title', 'type',
   *   'url', and other information as specified by the oEmbed standard.
   *   Otherwise, NULL.
   * http://archive.org/oembed/?url=http://archive.org/file/12345
   */
  public function getOEmbed() {
    $uri = media_archive_media_parse($this->embedCode);
    $external_url = drupal_realpath($uri);
    $oembed_url = url('http://archive.org/oembed', array('query' => array('url' => $external_url, 'format' => 'json')));
    $response = drupal_http_request($oembed_url);
    if (!isset($response->error)) {
      return drupal_json_decode($response->data);
    }
  }
}
