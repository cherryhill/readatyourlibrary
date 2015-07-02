jQuery(document).ready(function($) {
    jQuery('.page-openbadging .form-item-field-badge-entity-reference-1-und .form-checkbox').bind('click', function() {
			var title = this.id;
			var value = this.value;
				if ( document.getElementById(title).checked === true ) {
					$.post(Drupal.settings.baseRoot + Drupal.settings.basePath + 'ajax/privacy', { 'badge_id' : value}, function(response){
               if(response == 1){
               alert("This badge belongs to a private group. It will still be private until you remove it from the other group. Do you still want to continue?");
						   }
            });
				}
    });
});
