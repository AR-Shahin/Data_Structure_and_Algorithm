

$('.scroll-top').click(function(){
        $('html,body').animate({
            scrollTop : 0
        }),200;
    });
        $('.scroll-top').hide();
    $(window).scroll(function(){
        var count = $(this).scrollTop();

        if(count < 100){
            $('.scroll-top').fadeOut();
        }
        else{
            $('.scroll-top').fadeIn();
        }
    });