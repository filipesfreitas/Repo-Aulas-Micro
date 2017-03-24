var Templates = {};

Templates.codeExTable = [
    '<table class="table table-striped table-hover table-bordered table-condensed">',
      '<thead>',
        '<tr>',
        '<th>Project Name</th>',
        '<th>Description</th>',
        '</tr>',
      '</thead>',
      '<tbody>',
      '{{#each examples}}',
        '<tr>',
        '<td><a href="" onclick="createProject(\'{{SourcePreview}}\', \'{{Description}}\'); return false;">{{SourcePreview}}</td>',
        '<td>{{Description}}</td>',
        '</tr>',
      '{{/each}}',
      '</tbody>',
    '</table>'
].join("\n");

Templates.cSourceTable = [
    '<table class="table table-striped table-hover table-bordered table-condensed">',
      '<thead>',
        '<tr>',
        '<th>File Name</th>',
        '<th>Description</th>',
        '</tr>',
      '</thead>',
      '<tbody>',
      '{{#each examples}}',
        '<tr>',
        '{{{tableLink SourcePreview ".c"}}}',
        '<td>{{Description}}</td>',
        '</tr>',
      '{{/each}}',
      '</tbody>',
    '</table>'
].join("\n");

Templates.asmSourceTable = [
    '<table class="table table-striped table-hover table-bordered table-condensed">',
      '<thead>',
        '<tr>',
        '<th>File Name</th>',
        '<th>Description</th>',
        '</tr>',
      '</thead>',
      '<tbody>',
      '{{#each asmFiles}}',
        '<tr>',
        '{{{tableLink SourcePreview ".asm"}}}',
        '<td>{{Description}}</td>',
        '</tr>',
      '{{/each}}',
      '</tbody>',
    '</table>'
].join("\n");

Templates.toolsGrid = [
    '{{#each categories}}',
      '<h3>{{category}}</h3>',
        '{{#grid tools}}',
          '<div class="span3">',
            '<div class="thumbnail">',
              '<a href="liveaction:SetFilterTextAction({{filter}})" onclick="$(\'#{{id}}_modal\').modal(\'show\'); return true;">',
                '<img src="assets/photos/{{id}}_square.png" alt="{{title}}" class="img-responsive"></a>',
              '<div class="caption">',
                '<h4 class="text-center">{{title}}</h4>',
              '</div>',
            '</div>',
          '</div>',
        '{{/grid}}',
    '{{/each}}'
].join("\n");

Templates.toolsModal = [
    '{{#each categories}}',
    '{{#each tools}}',
    '<div class="modal hide fade" id="{{id}}_modal" tabindex="-1" role="dialog" aria-hidden="true" data-replace="true">',
    '<div class="modal-header">',
      '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>',
      '<h3 class="modal-title">{{title}}</h3>',
    '</div>',
    '<div class="modal-body">',
      '<div style="overflow:hidden;">',
        '<div style="float: right;">',
          '<img src="assets/photos/{{id}}_thumb.png" class="img-responsive modal-img">',
        '</div>',
        '{{{description}}}',
      '</div>',
    '</div>',
    '<div class="modal-footer">',
      '{{#each buttons}}',
      '<button type="button" style="float:left;" class="btn btn-primary" onclick="location.href = \'{{link}}\'">{{text}}</button>',
      '{{/each}}',
      '<button type="button" class="btn btn-default" data-dismiss="modal">Close</button>',
    '</div>',
    '</div>',
    '{{/each}}',
    '{{/each}}'
].join("\n");

Templates.trainingsGrid = [
  '{{#each categories}}',
    '<h3>{{category}}</h3>',
    '{{#grid trainings}}',
      '<div class="span3">',
        '<div class="thumbnail">',
          '<a data-toggle="modal" href="#{{id}}_modal">',
            '<img src="assets/photos/{{id}}_square.png" alt="{{title}}" class="img-responsive"></a>',
          '<div class="caption">',
            '<h4 class="text-center">{{title}}</h4>',
          '</div>',
        '</div>',
      '</div>',
    '{{/grid}}',
  '{{/each}}',
].join("\n");

Templates.trainingsModal = [
    '{{#each categories}}',
    '{{#each trainings}}',
    '<div class="modal hide fade" id="{{id}}_modal" tabindex="-1" role="dialog" aria-hidden="true">',
    '<div class="modal-header">',
      '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>',
      '<h3 class="modal-title">{{title}}</h3>',
    '</div>',
    '<div class="modal-body">',
      '{{#if src}}',
      '<div class="text-center">',
        '<iframe width="{{width}}" height="{{height}}" src="https://www.youtube.com/embed/{{src}}?html5=1" frameborder="0" allowfullscreen></iframe>',
      '</div>',
      '{{else}}',
      '<div style="float: right;">',
        '<img src="assets/photos/{{id}}_thumb.png" class="img-responsive modal-img">',
      '</div>',
      '{{{description}}}',
      '{{/if}}',
    '</div>',
    '<div class="modal-footer">',
      '{{#each buttons}}',
      '<button type="button" style="float:left;" class="btn btn-primary" onclick="location.href = \'{{link}}\'">{{text}}</button>',
      '{{/each}}',
      '<button type="button" class="btn btn-default" data-dismiss="modal">Close</button>',
    '</div>',
    '</div>',
    '{{/each}}',
    '{{/each}}',
].join("\n");

Templates.devicesGrid = [
    '{{#grid devices}}',
      '<div class="span3">',
        '<div class="thumbnail">',
          '<a href="liveaction:SetFilterTextAction({{filter}})" onclick="$(\'#{{id}}_modal\').modal(\'show\'); return true;">',
            '<img src="assets/photos/{{id}}_square.png" alt="{{title}}" class="img-responsive"></a>',
        '</div>',
      '</div>',
    '{{/grid}}'
].join("\n");

Templates.devicesModal = [
    '{{#each devices}}',
    '<div class="modal hide fade" id="{{id}}_modal" tabindex="-1" role="dialog" aria-hidden="true">',
      '<div class="modal-header">',
        '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>',
        '<h3 class="modal-title">{{title}}</h3>',
      '</div>',
      '<div class="modal-body">',
        '<div style="overflow:hidden;">',
          '<div style="float: right;">',
            '<img src="assets/photos/{{id}}_square.png" class="img-responsive modal-img">',
          '</div>',
          '{{{description}}}',
        '</div>',
      '</div>',
      '<div class="modal-footer">',
        '<button type="button" class="btn btn-default" data-dismiss="modal">Close</button>',
      '</div>',
    '</div>',
    '{{/each}}'
].join("\n");


Templates.librariesGrid = [
    '{{#grid libraries}}',
      '<div class="span3">',
        '<div class="thumbnail">',
          '<a href="liveaction:SetFilterTextAction({{filter}})" onclick="$(\'#{{id}}_modal\').modal(\'show\'); return true;">',
            '<img src="assets/photos/{{id}}_square.png" alt="{{title}}" class="img-responsive"></a>',
        '</div>',
      '</div>',
    '{{/grid}}'
].join("\n");

Templates.librariesModal = [
    '{{#each libraries}}',
    '<div class="modal hide fade" id="{{id}}_modal" tabindex="-1" role="dialog" aria-hidden="true">',
    '<div class="modal-header">',
      '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>',
      '<h3 class="modal-title">{{title}}</h3>',
    '</div>',
    '<div class="modal-body">',
      '<div style="overflow:hidden;">',
        '<div style="float: right;">',
          '<img src="assets/photos/{{id}}_thumb.png" class="img-responsive modal-img">',
        '</div>',
        '{{{description}}}',
      '</div>',
    '</div>',
    '<div class="modal-footer">',
      '{{#each buttons}}',
      '<button type="button" style="float:left;" class="btn btn-primary" onclick="location.href = \'{{link}}\'">{{text}}</button>',
      '{{/each}}',
      '<button type="button" class="btn btn-default" data-dismiss="modal">Close</button>',
    '</div>',
    '</div>',
    '{{/each}}',
].join("\n");

Templates.rtosGrid = [
  '{{#grid libraries}}',
    '<div class="span3">',
      '<div class="thumbnail">',
        '<a href="liveaction:SetFilterTextAction({{filter}})" onclick="$(\'#{{id}}_modal\').modal(\'show\'); return true;">',
          '<img src="assets/photos/{{id}}_square.png" alt="{{title}}" class="img-responsive"></a>',
        '<div class="caption">',
          '<h4 class="text-center">{{title}}</h4>',
        '</div>',
      '</div>',
    '</div>',
  '{{/grid}}',
].join("\n");

Templates.rtosModal = Templates.librariesModal;

Templates.navbar = [
  '<div class="navbar navbar-inverse navbar-fixed-top">',
    '<div class="navbar-inner">',
      '<div class="container">',
        '<button type="button" class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">',
          '<span class="icon-bar"></span>',
          '<span class="icon-bar"></span>',
          '<span class="icon-bar"></span>',
        '</button>',
        '{{#if folder}}',
          '<a class="brand" href="{{folder}}/index.html">MSP430Ware</a>',
        '{{else}}',
          '<a class="brand" href="index.html">MSP430Ware</a>',
        '{{/if}}',
        '<div class="nav-collapse collapse">',
          '<ul class="nav pull-right">',
            '{{#navbar itemsRight}}',
                '<a href="{{page}}">{{text}}</a>',
            '{{/navbar}}',
          '</ul>',
          '<ul class="nav">',
            '{{#navbar itemsLeft}}',
                '<a href="{{page}}">{{text}}</a>',
            '{{/navbar}}',
          '</ul>',
        '</div>',
      '</div>',
    '</div>',
  '</div>'
].join("\n");

Templates.footer = [
    '<hr>',
      '<footer>',
        '<p>Version 3.60.00.10</p>',
        '<p>&copy; Texas Instruments 2016</p>',
      '</footer>'
].join("\n");

Templates.thirdPartyButton = [
    '<a href="{{link}}" class="btn btn-success">Visit Third Party Website</a>'
].join("\n");
