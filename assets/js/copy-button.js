window.addEventListener('load', function(){
    const unbundle = function () {
        $('#unbundled').each(function(index, element) {
            $(element).parent().next().show();
        });
        $('#bundled').each(function(index, element) {
            $(element).parent().next().hide();
        });
        $('.code-bundle-btn').each(function(index, element) {
            $(element).text("Bundle");
        });
    };
    const bundle = function () {
        $('#unbundled').each(function(index, element) {
            $(element).parent().next().hide();
        });
        $('#bundled').each(function(index, element) {
            $(element).parent().next().show();
        });
        $('.code-bundle-btn').each(function(index, element) {
            $(element).text("Unbundle");
        });
    };
    // bundle されたコードは最初は非表示に
    let is_bundled = false;
    unbundle();

    // ボタンを実装
    $('pre > code').each(function(index, element) {
        $(element).parent().wrap('<div style="position: relative;"></div>');
        $(element).parent().parent().append('<button type="button" class="code-btn code-copy-btn" title="Copied!">Copy</button>');
        $(element).parent().parent().append('<button type="button" class="code-btn code-bundle-btn" title="Bundled!">Bundle</button>');
    });

    $('.code-copy-btn').on('click',function(){
        // テキスト要素を選択＆クリップボードにコピー
        var textElem = $(this).siblings(':first');
        window.getSelection().selectAllChildren(textElem[0]);
        document.execCommand("copy");
        window.getSelection().removeAllRanges();
        
        // コピー完了した後の処理
        // トースト通知とかすると親切かも...
        $(this).showBalloon();
        const this_ = this;
        setTimeout(function() {
            $(this_).hideBalloon();
        }, 300);
    });

    $('.code-bundle-btn').on('click', function(){
        // bundle / unbundle の切り替え
        if (is_bundled) {
            unbundle();
        } else {
            bundle();
        }
        is_bundled = ! is_bundled;
    });
});
