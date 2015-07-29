jQuery(document).ready(function($) {
    //Bind send buttons to the OpenBadges function.
    jQuery('.achievement-openbadges-backpack-button').bind('click', function() {
        //Build the url for the assertion and call the OpenBadges function to 
        // issue the assertion.
        var title = this.id;
        var url = Drupal.settings.baseRoot + Drupal.settings.basePath + 'openbadging_amobb/assertions/' + encodeURIComponent(title) + '/' + Drupal.settings.uid;
        OpenBadges.issue([url], function(errors, successes) {
            // For logging errors.
            //alert(errors[0]['url']+errors[0]['reason']);
            });
    });
});

