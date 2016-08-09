<?php
class Play {

  private static $instance;

  private function __construct() {}

  public function __clone()
  {
    trigger_error('Clone is not allowed.', E_USER_ERROR);
  }

  public static function getInstance() {
    if(!isset(self::$instance)) {
      $c = __CLASS__;
      self::$instance = new $c;
    }
    return self::$instance;
  }

  /**
  * function to perform db select from file managed for images
  * provides program logo through platform configuration page
  *
  * @param
  *  String $style Image style name
  *  Variable $imageFid fid of the image
  *
  * @return
  *  Image
  */

  public function program_logo_teen($imageFid, $style = '') {
    if($imageFid == ''){
      return FALSE;
    }
    if($style == ''){
      $style = 'medium';
    }

    $query = db_select('file_managed', 'file')
      ->fields('file', array('uri'))
      ->condition('fid', $imageFid)
      ->execute()
      ->fetchAssoc();

    $img_uri_path = $query['uri'];
    $img_path = image_style_url($style, $img_uri_path);
    $img = "<img src='$img_path'>";
    if ($img_uri_path){
      return $img;
    }
  }

} // Play ends here.
?>

