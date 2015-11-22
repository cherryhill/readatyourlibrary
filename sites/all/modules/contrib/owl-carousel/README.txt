 This module will aim to provide both field & views integration. However the current dev release only offers 
 basic views integration.

 /* Install */
 Owl Carousel can be downloaded from http://owlgraphic.com/owlcarousel/. Once complete copy
 the owl-carousel folder into the libraries directory with the following path, sites\all\libraries\owl-carousel.
 Please also download & install the jQuery update module. Owl Carousel requires jQuery 1.7 or higher.
  
 /* Use */
 After installing the views sub module the display format will become available when 
 creating views at admin/structure/views/add. Please remember to also configure jQuery Update 
 at admin/config/development/jquery_update as the default version 1.5 will need to be switched to 1.7.
 
 /* Note */
 If you are getting this error, TypeError: t.$elem.data(...) is undefined. Please change your jQuery version
 to 1.8, this is required until the patch below is merged into Owlcarousel.
 @ref, https://github.com/OwlFonk/OwlCarousel/pull/133
