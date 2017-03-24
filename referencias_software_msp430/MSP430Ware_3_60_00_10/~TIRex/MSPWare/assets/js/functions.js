
var getUrlVars = function() {
    var vars = {};

    var parts = window.location.href.replace(/[?&]+([^=&]+)=([^&]*)/gi, function(m,key,value) {
        vars[key] = value;
    });

    return vars;
};

var getArch = function() {
    return 'msp430';
}

/**
 * This parses the URL variables for the id variable and then launches a modal
 * with that id
 */
var LaunchModal = function() {

    var id = getUrlVars()["id"];

    if(typeof id !== 'undefined') {
        var name = '#' + id + '_modal';
        $(name).modal();
        $(name).modal('show');
    }
};

var CreateCodeExamplesTable = function(codeExTemplate, data) {

    var source = codeExTemplate;
    var template = Handlebars.compile(source);
    var html = template(data);
    document.getElementById("examples").innerHTML = html;
};

var CreateCFilesExamplesTable = function(cSourceTemplate, data) {

    var source = cSourceTemplate;
    var template = Handlebars.compile(source);
    var html = template(data);
    document.getElementById("cSourceFiles").innerHTML = html;
};

var CreateASMFilesExamplesTable = function(asmSourceTemplate, data) {

    var source = asmSourceTemplate;
    var template = Handlebars.compile(source);
    var html = template(data);
    document.getElementById("asmSourceFiles").innerHTML = html;
};

var CreateGridModals = function(gridTemplate, modalTemplate, data) {

      Handlebars.registerHelper('grid', function(context, options) {
        var ret = "";
        var j = 0;
        var arch = getArch();
        for(var i = 0; i < context.length; i++) {

          if(context[i].arch === arch || context[i].arch === "both") {
              console.log(j);
              if((j % 4) === 0) {
                ret = ret + "<div class=\"thumbnails\">";
              }

              ret = ret + options.fn(context[i]);

              if(i === (context.length - 1)) {
                ret = ret + "</div>";
              } else if ((j % 4) === 3) {
                ret = ret + "</div>";
              }
              j++;
          } else {
              if(i === (context.length - 1)) {
                ret = ret + "</div>";
              }
          }
        }
        return ret;
    });

    var source = gridTemplate;
    var template = Handlebars.compile(source);
    var html = template(data);
    document.getElementById("grid").innerHTML = html;

    source = modalTemplate;
    template = Handlebars.compile(source);
    html = template(data);
    document.getElementById("modals").innerHTML = html;
};


var CreateFooter = function(footerTemplate) {

    var source = footerTemplate;
    var template = Handlebars.compile(source);
    var html = template();

    document.getElementById("footer").innerHTML = html;
};


var CreateThirdPartyButton = function(buttonTemplate) {

    var source = buttonTemplate;
    var link = {link: getUrlVars()["link"]};
    var template = Handlebars.compile(source);
    var html = template(link);

    document.getElementById("thirdPartyButton").innerHTML = html;
};

/**
 * Creates the html for a navigation bar. The Handlebars template correctly
 * highlights the current page.
 */
var CreateNavbar = function(navbarTemplate, startFolder) {


    startFolder = (typeof startFolder === "undefined") ? "." : startFolder;

    Handlebars.registerHelper('navbar', function(context, options) {

        var ret ="";

        var path = window.location.pathname;
        var page = path.substring(path.lastIndexOf('/') + 1);

        for(var i = 0; i < context.length; i++) {

            if(context[i].page === page) {
                ret = ret + '<li class="active">' + options.fn(context[i]) + '</li>';
            } else {
                ret = ret + '<li>' + options.fn(context[i]) + '</li>';
            }
        }
        return ret;
    });

    source = navbarTemplate;
    template = Handlebars.compile(source);
    html = template(Navbar);
    document.getElementById("navbar").innerHTML = html;
};

var GetMSPWareRoot = function() {
    var windowPath = window.location.pathname;
    var root = windowPath.replace("code_ex.html", "../../");
    root = root.replace("/", "");
    return root;
};

function replaceAll(find, replace, str) {
    return str.replace(new RegExp(find, 'g'), replace);
}
