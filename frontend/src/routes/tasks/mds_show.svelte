<script>
	import { useForm, validators, email, required } from "svelte-use-form";

/*const form = useForm();

async function doPost() {
    const { email, password } = $form;
    const data = {
        email: email?.value,
        password: password?.value,
    };

    const res = await fetch("/api/users/login", {
        method: "POST",
        mode: "no-cors",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify(data),
    });
}*/

</script>

<svelte:head>
    <link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Ubuntu:regular,bold&subset=Latin">
	<title>Lorem Ipsum</title>
	<meta name="Task page" content="Login page" />
</svelte:head>

<body>
    
    <!--<div class="header">
        h1 style="font-family: Ubuntu;">ReadMe</h1>
        <h1>Read Me</h1>
    </div>-->
    <div class="Win" style="width: 98%; margin-left: 1%; min-height: 32px; height: 46px; margin-top: 8px; float: top; text-align: center;">
        <h2 style="font-family: Ubuntu; margin-top: 8px;">Task Name</h2>
    </div>
    <div class="Win">                                   <!-- left - readme -->
        <div class="Button"></div>
        <div class="Button" style="background-color: rgb(212, 192, 8); margin-right: 12px;"></div>
        <div class="Button" style="background-color: rgb(62, 185, 4); margin-right: 12px; "></div>
    <md-block class="MD" style="margin-top: 28px;">
        <!--style="margin-left: 16px; margin-right: 16px; margin-top: 64px;"-->
        <p class="MD">Phishing je hromadný útok na určitou skupinu za <u><i>účelem finančního
        zisku či poškození firmy nebo  osoby</i></u>. Phishing má po většinu času
        podobu hromadného rozesílání<b> emailu</b> můžete se však setkat i v
        podobě telefoních zpráv.  Ve zprávě se mohou objevit odkazy na webové
        stránky či přílohy. V takémto emailu může být i příloha. <b>Přílohu a
        odkazy v případě podezření na phishing nikdy nestahujeme a nikdy
        neotevíráme!</b>
        <!----></md-block>
        <md-block>
            <p class="MD">Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec vitae arcu. Nunc dapibus tortor vel mi dapibus sollicitudin. Nulla accumsan, elit sit amet varius semper, nulla mauris mollis quam, tempor suscipit diam nulla vel leo. Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Donec ipsum massa, ullamcorper in, auctor et, scelerisque sed, est. In dapibus augue non sapien. Fusce aliquam vestibulum ipsum. Donec quis nibh at felis congue commodo. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Vestibulum erat nulla, ullamcorper nec, rutrum non, nonummy ac, erat. Pellentesque arcu. Vivamus luctus egestas leo. Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur? Donec ipsum massa, ullamcorper in, auctor et, scelerisque sed, est. Nullam sapien sem, ornare ac, nonummy non, lobortis a enim.</p>

            <p class="MD">Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Duis risus. Cras elementum. Pellentesque ipsum. Nunc tincidunt ante vitae massa. Maecenas ipsum velit, consectetuer eu lobortis ut, dictum at dui. Nulla quis diam. Integer imperdiet lectus quis justo. Donec vitae arcu. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. In rutrum. Fusce aliquam vestibulum ipsum. Nullam sapien sem, ornare ac, nonummy non, lobortis a enim. Etiam posuere lacus quis dolor. Integer imperdiet lectus quis justo. Nulla turpis magna, cursus sit amet, suscipit a, interdum id, felis. Fusce nibh. Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Curabitur bibendum justo non orci.</p>

            <p class="MD">Nulla non lectus sed nisl molestie malesuada. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Nam sed tellus id magna elementum tincidunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. In dapibus augue non sapien. Quisque tincidunt scelerisque libero. Quisque porta. In dapibus augue non sapien. Mauris metus. Suspendisse nisl. Proin in tellus sit amet nibh dignissim sagittis. Mauris metus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. In dapibus augue non sapien.</p>
            <p class="MD">Nulla non lectus sed nisl molestie malesuada. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Nam sed tellus id magna elementum tincidunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. In dapibus augue non sapien. Quisque tincidunt scelerisque libero. Quisque porta. In dapibus augue non sapien. Mauris metus. Suspendisse nisl. Proin in tellus sit amet nibh dignissim sagittis. Mauris metus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. In dapibus augue non sapien.</p>
            <p class="MD">Nulla non lectus sed nisl molestie malesuada. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Nam sed tellus id magna elementum tincidunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. In dapibus augue non sapien. Quisque tincidunt scelerisque libero. Quisque porta. In dapibus augue non sapien. Mauris metus. Suspendisse nisl. Proin in tellus sit amet nibh dignissim sagittis. Mauris metus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. In dapibus augue non sapien.</p>
            <p class="MD">Nulla non lectus sed nisl molestie malesuada. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Nam sed tellus id magna elementum tincidunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. In dapibus augue non sapien. Quisque tincidunt scelerisque libero. Quisque porta. In dapibus augue non sapien. Mauris metus. Suspendisse nisl. Proin in tellus sit amet nibh dignissim sagittis. Mauris metus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. In dapibus augue non sapien.</p>
            <p class="MD">Nulla non lectus sed nisl molestie malesuada. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Nam sed tellus id magna elementum tincidunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. In dapibus augue non sapien. Quisque tincidunt scelerisque libero. Quisque porta. In dapibus augue non sapien. Mauris metus. Suspendisse nisl. Proin in tellus sit amet nibh dignissim sagittis. Mauris metus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. In dapibus augue non sapien.</p>
        </md-block>
    </div>
    <div>                                           <!-- right - answers -->
        <div class="Win" style="margin-left: auto; margin-right: 1%; float: right; ">
            <div class="Button"></div>
            <div class="Button" style="background-color: rgb(212, 192, 8); margin-right: 12px;"></div>
            <div class="Button" style="background-color: rgb(62, 185, 4); margin-right: 12px; "></div>
            <md-block class="MD" style="margin-top: 28px;">
                <p class="MD">Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec vitae arcu. Nunc dapibus tortor vel mi dapibus sollicitudin. Nulla accumsan, elit sit amet varius semper, nulla mauris mollis quam, tempor suscipit diam nulla vel leo. Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Donec ipsum massa, ullamcorper in, auctor et, scelerisque sed, est. In dapibus augue non sapien. Fusce aliquam vestibulum ipsum. Donec quis nibh at felis congue commodo. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Vestibulum erat nulla, ullamcorper nec, rutrum non, nonummy ac, erat. Pellentesque arcu. Vivamus luctus egestas leo. Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur? Donec ipsum massa, ullamcorper in, auctor et, scelerisque sed, est. Nullam sapien sem, ornare ac, nonummy non, lobortis a enim.</p>
            </md-block>
        </div>
    </div>
</body>

<style>

    body {
        background-color: rgba(48, 48, 48, 1);
        background-position: center;
        background-repeat:round;
        background-size: cover;
        background-image: url("file:///home/tea/Documents/.hacka/Cyber-Lite/frontend/src/routes/tasks/cool-background.png");
    }
    .Win{
        color: rgba(00, 00, 00, 1);
        font-family: Ubuntu;
        text-align: left; 
        border-radius: 16px;
        background-color: rgba(17, 17, 17, 0.45);
        width: 48%;
        height: 75%;
        float:left;
        min-height: 704px;
        margin-left: 1%;
        margin-top: 48px;
        backdrop-filter: blur(6px);
        overflow-y: auto;
        scrollbar-height: thin;
        /*border-color: rgba(24, 24, 24, 0.5);
        border-width: 2px;
        border-style: solid;*/
    }
    .MD{
        font-family: Ubuntu;
        text-align: left;
        margin-left: 16px;
        margin-right: 16px;
        margin-top: 24px;
        text-align: left;
    }
    .Button{
        background-color: rgb(225, 0, 0);
        width: 14px;
        height: 14px;
        border-radius: 30px;
        margin-left: auto;
        margin-right: 16px;
        margin-bottom: auto;
        margin-top: 16px;
        float: right;
        border-color: rgba(24, 24, 24, 1);
        border-width: 1px;
        border-style: outset;
        overflow-y: hidden;
    }
</style>
