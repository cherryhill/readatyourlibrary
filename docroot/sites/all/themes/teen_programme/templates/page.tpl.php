
  <!--.l-header region -->
  <header role="banner" class="l-header">

    <!-- City Branding -->
    <div class="pre-header">
      <section class="row" id="topmostbranding">
        <div class="mobile-hamburger hide-for-medium-up">
          <button class="hamburger">
             <span class="icon"></span>
             <span class="icon"></span>
             <span class="icon"></span>
          </button>
        </div>
        <div class="top-menu hide-for-only-small">
          <?php if (!empty($page['top_links'])): ?>
          <?php print render($page['top_links']); ?>
          <?php endif; ?>
        </div>
      <!--mobile menu-->
      <section class="mobile-menu-wrapper">
      <div class="mobile-menu columns">
        <?php if (!empty($page['mobile_menu'])): ?>
        <?php print render($page['mobile_menu']); ?>
        <?php endif; ?>
      </div>
      </section>
    </section>
    </div>
    <!-- End City Branding and Account Links -->

    <!-- Title, slogan and menu -->
    <section class="row header-middle">
     <div class="logo-block">
     <div class="site-info">
     <div class="logo">
      <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>
     </div>
     <div class="site-desc">
        <?php if ($site_name): ?>
          <h1 title="<?php print $site_name; ?>" id="site-name" class="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print $site_name; ?>"><?php print $site_name; ?></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <h2 title="<?php print $site_slogan; ?>" id="site-slogan" class="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
        </div>
        </div>
        <div class="program-logo">
    <?php if (!empty($page['header'])): ?>
      <?php print render($page['header']); ?>
      <?php endif; ?></div>
    </div>

    <div class="main-menu hide-for-only-small">
      <div class="menu-wrapper">
      <?php if (!empty($page['main_menu'])): ?>
      <?php print render($page['main_menu']); ?>
      <?php endif; ?>
      </div>
    </div>

    </section>
    <!-- End title, slogan and menu, plus header -->

  </header>
  <!--/.l-header -->

  <?php if (!empty($page['featured'])): ?>
    <!--/.featured -->
    <section class="l-featured row">
      <div class="large-12 columns">
        <?php print render($page['featured']); ?>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>

  <?php if ($messages && !$zurb_foundation_messages_modal): ?>
    <!--/.l-messages -->
    <section class="l-messages row">
      <div class="large-12 columns">
        <?php if ($messages): print $messages; endif; ?>
      </div>

    </section>
    <!--/.l-messages -->
  <?php endif; ?>

  <?php if (!empty($page['help'])): ?>
    <!--/.l-help -->
    <section class="l-help row">
      <div class="large-12 columns">
        <?php print render($page['help']); ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>
  <div class="row breadcrum-wrapper">
     <div class="breadcurm large-12 columns">
          <?php if ($breadcrumb): print $breadcrumb; endif; ?>
        </div>

  </div>

  <main role="main" class="row l-main">

    <div class="<?php print $main_grid; ?> main columns">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

      <a id="main-content"></a>

      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 id="page-title" class="title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if (!empty($tabs)): ?>
        <div class="primary-tabs"><?php print render($tabs); ?></div>
        <?php if (!empty($tabs2)): ?>
          <div class="secondary-tabs"><?php print render($tabs2); ?></div>
        <?php endif; ?>
      <?php endif; ?>

      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>

      <?php print render($page['content']); ?>
    </div>
    <!--/.main region -->
      <?php if (!empty($page['sidebar_shareit'])): ?>
      <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-shareit columns sidebar2">
        <div class='first'><?php print render($page['sidebar_shareit']); ?> </div>
      </aside>
    <?php endif; ?>
      <?php if (!empty($page['sidebar_activity'])): ?>
      <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-activity columns sidebar2">
        <div class='first'><?php print render($page['sidebar_activity']); ?> </div>
      </aside>
    <?php endif; ?>
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside role="complementary" class="<?php print $sidebar_first_grid; ?> sidebar-first columns sidebar">
        <div class='first'><?php print render($page['sidebar_first']); ?> </div>
      </aside>
    <?php endif; ?>




    <?php if (!empty($page['sidebar_second'])): ?>
      <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </main>
  <!--/.main-->

  <?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'])): ?>
    <!--.triptych-->
    <section class="l-triptych row">
      <div class="triptych-first large-4 smallmedium-6 small-12 columns">
        <?php print render($page['triptych_first']); ?>
      </div>
      <div class="triptych-middle large-4 smallmedium-6 small-12 columns">
        <?php print render($page['triptych_middle']); ?>
      </div>
      <div class="triptych-last large-4 smallmedium-12 small-12 columns">
        <?php print render($page['triptych_last']); ?>
      </div>
    </section>
    <!--/.triptych -->
  <?php endif; ?>

  <?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>
    <!--.footer-columns -->
    <div class="contain-to-grid footcols">
    <section class="row l-footer-columns">
      <?php if (!empty($page['footer_firstcolumn'])): ?>
        <div class="footer-first large-3 smallmedium-6 small-12 columns">
          <?php print render($page['footer_firstcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_secondcolumn'])): ?>
        <div class="footer-second large-3 smallmedium-6 small-12 columns">
          <?php print render($page['footer_secondcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_thirdcolumn'])): ?>
        <div class="footer-third large-3 smallmedium-6 small-12 columns">
          <?php print render($page['footer_thirdcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth large-3 smallmedium-6 small-12 columns">
          <?php print render($page['footer_fourthcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    </div>
    <!--/.footer-columns-->
  <?php endif; ?>

  <!--.l-footer-->
    <div class="post-footer contain-to-grid">
      <footer class="l-footer row" role="contentinfo">
        <?php if (!empty($page['footer'])): ?>
          <div class="footer large-12 columns">
            <?php print render($page['footer']); ?>
          </div>
        <?php endif; ?>
      </footer>
      </div>
    <div class="contain-to-grid">
  <!--/.footer-->

  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>
<!--/.page -->

