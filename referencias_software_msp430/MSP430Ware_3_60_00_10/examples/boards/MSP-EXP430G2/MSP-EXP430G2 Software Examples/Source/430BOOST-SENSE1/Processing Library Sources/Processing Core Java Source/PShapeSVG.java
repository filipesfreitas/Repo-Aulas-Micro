



<!DOCTYPE html>
<html>
<head>
 <link rel="icon" type="image/vnd.microsoft.icon" href="http://www.gstatic.com/codesite/ph/images/phosting.ico">
 
 <script type="text/javascript">
 
 (function(){function a(e){this.t={};this.tick=function(f,c,d){c=d!=undefined?d:(new Date).getTime();this.t[f]=c};this.tick("start",null,e)}var b=new a;window.jstiming={Timer:a,load:b};try{var g=null;if(window.chrome&&window.chrome.csi)g=Math.floor(window.chrome.csi().pageT);if(g==null)if(window.gtbExternal)g=window.gtbExternal.pageT();if(g==null)if(window.external)g=window.external.pageT;if(g)window.jstiming.pt=g}catch(h){};})();

 
 
 
 var codesite_token = "c6974bcd72eb95455827185f7306e1fa";
 
 
 var logged_in_user_email = "Dung.Dang@gmail.com";
 
 
 var relative_base_url = "";
 
 </script>
 
 
 <title>PShapeSVG.java - 
 processing -
 
 Project Hosting on Google Code</title>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/10276742928614796628/css/ph_core.css">
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/10276742928614796628/css/ph_detail.css" >
 
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/10276742928614796628/css/d_sb_20080522.css" >
 
 
 
<!--[if IE]>
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/10276742928614796628/css/d_ie.css" >
<![endif]-->
 <style type="text/css">
 .menuIcon.off { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -42px }
 .menuIcon.on { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -28px }
 .menuIcon.down { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 0; }
 
 
 
  tr.inline_comment {
 background: #fff;
 vertical-align: top;
 }
 div.draft, div.published {
 padding: .3em;
 border: 1px solid #999; 
 margin-bottom: .1em;
 font-family: arial, sans-serif;
 max-width: 60em;
 }
 div.draft {
 background: #ffa;
 } 
 div.published {
 background: #e5ecf9;
 }
 div.published .body, div.draft .body {
 padding: .5em .1em .1em .1em;
 max-width: 60em;
 white-space: pre-wrap;
 white-space: -moz-pre-wrap;
 white-space: -pre-wrap;
 white-space: -o-pre-wrap;
 word-wrap: break-word;
 font-size: 1em;
 }
 div.draft .actions {
 margin-left: 1em;
 font-size: 90%;
 }
 div.draft form {
 padding: .5em .5em .5em 0;
 }
 div.draft textarea, div.published textarea {
 width: 95%;
 height: 10em;
 font-family: arial, sans-serif;
 margin-bottom: .5em;
 }

 
 .nocursor, .nocursor td, .cursor_hidden, .cursor_hidden td {
 background-color: white;
 height: 2px;
 }
 .cursor, .cursor td {
 background-color: darkblue;
 height: 2px;
 display: '';
 }
 
 
.list {
 border: 1px solid white;
 margin-bottom:0;
}

 </style>
</head>
<body class="t4">
 <script type="text/javascript">
 var _gaq = _gaq || [];
 _gaq.push(
 ['siteTracker._setAccount', 'UA-18071-1'],
 ['siteTracker._trackPageview']);
 
 (function() {
 var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
 ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
 (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
 })();
 </script>
<div class="headbg">
 <div id="gaia">
 
 <span>
 
 
 <b>Dung.Dang@gmail.com</b>
 
 
 | <a href="/u/@VhVRRVJYBRNNWwl6/" id="projects-dropdown" onclick="return false;"
 ><u>My favorites</u> <small>&#9660;</small></a>
 | <a href="/u/@VhVRRVJYBRNNWwl6/" onclick="_CS_click('/gb/ph/profile');" 
 title="Profile, Updates, and Settings"
 ><u>Profile</u></a>
 | <a href="https://www.google.com/accounts/Logout?continue=http%3A%2F%2Fcode.google.com%2Fp%2Fprocessing%2Fsource%2Fbrowse%2Ftrunk%2Fprocessing%2Fcore%2Fsrc%2Fprocessing%2Fcore%2FPShapeSVG.java" 
 onclick="_CS_click('/gb/ph/signout');"
 ><u>Sign out</u></a>
 
 </span>

 </div>
 <div class="gbh" style="left: 0pt;"></div>
 <div class="gbh" style="right: 0pt;"></div>
 
 
 <div style="height: 1px"></div>
<!--[if lte IE 7]>
<div style="text-align:center;">
Your version of Internet Explorer is not supported. Try a browser that
contributes to open source, such as <a href="http://www.firefox.com">Firefox</a>,
<a href="http://www.google.com/chrome">Google Chrome</a>, or
<a href="http://code.google.com/chrome/chromeframe/">Google Chrome Frame</a>.
</div>
<![endif]-->




 <table style="padding:0px; margin: 0px 0px 10px 0px; width:100%" cellpadding="0" cellspacing="0">
 <tr style="height: 58px;">
 
 <td id="plogo">
 <a href="/p/processing/">
 
 <img src="http://www.gstatic.com/codesite/ph/images/defaultlogo.png" alt="Logo">
 
 </a>
 </td>
 
 <td style="padding-left: 0.5em">
 
 <div id="pname">
 <a href="/p/processing/">processing</a>
 </div>
 <div id="psum">
 <a id="project_summary_link" href="/p/processing/" >An open source programming language and environment for images, animation, and interactions.</a>
 
 </div>
 
 </td>
 <td style="white-space:nowrap;text-align:right; vertical-align:bottom;">
 
 <form action="/hosting/search">
 <input size="30" name="q" value="" type="text">
 <input type="submit" name="projectsearch" value="Search projects" >
 </form>
 
 </tr>
 </table>

</div>

 
<div id="mt" class="gtb"> 
 <a href="/p/processing/" class="tab ">Project&nbsp;Home</a> 
 
 
 
 
 <a href="/p/processing/downloads/list" class="tab ">Downloads</a>
 
 
 
 
 
 <a href="/p/processing/w/list" class="tab ">Wiki</a>
 
 
 
 
 
 <a href="/p/processing/issues/list"
 class="tab ">Issues</a>
 
 
 
 
 
 <a href="/p/processing/source/checkout"
 class="tab active">Source</a>
 
 
 
 <div class=gtbc></div>
</div>
<table cellspacing="0" cellpadding="0" width="100%" align="center" border="0" class="st">
 <tr>
 
 
 
 
 
 
 <td class="subt">
 <div class="st2">
 <div class="isf">
 
 
 
 <span class="inst1"><a href="/p/processing/source/checkout">Checkout</a></span> &nbsp;
 <span class="inst2"><a href="/p/processing/source/browse/trunk/processing">Browse</a></span> &nbsp;
 <span class="inst3"><a href="/p/processing/source/list">Changes</a></span> &nbsp;
 
 <form action="http://www.google.com/codesearch" method="get" style="display:inline"
 onsubmit="document.getElementById('codesearchq').value = document.getElementById('origq').value + ' package:http://processing\\.googlecode\\.com'">
 <input type="hidden" name="q" id="codesearchq" value="">
 <input type="text" maxlength="2048" size="38" id="origq" name="origq" value="" title="Google Code Search" style="font-size:92%">&nbsp;<input type="submit" value="Search Trunk" name="btnG" style="font-size:92%">
 
 
 
 </form>
 </div>
</div>

 </td>
 
 
 
 <td align="right" valign="top" class="bevel-right"></td>
 </tr>
</table>
<script type="text/javascript">
 var cancelBubble = false;
 function _go(url) { document.location = url; }
</script>


<div id="maincol"
 
>

 
<!-- IE -->




<div class="expand">
<div id="colcontrol">
<style type="text/css">
 #file_flipper { white-space: nowrap; padding-right: 2em; }
 #file_flipper.hidden { display: none; }
 #file_flipper .pagelink { color: #0000CC; text-decoration: underline; }
 #file_flipper #visiblefiles { padding-left: 0.5em; padding-right: 0.5em; }
</style>
<table id="nav_and_rev" class="list"
 cellpadding="0" cellspacing="0" width="100%">
 <tr>
 
 <td nowrap="nowrap" class="src_crumbs src_nav" width="33%">
 <strong class="src_nav">Source path:&nbsp;</strong>
 <span id="crumb_root">
 
 <a href="/p/processing/source/browse/">svn</a>/&nbsp;</span>
 <span id="crumb_links" class="ifClosed"><a href="/p/processing/source/browse/trunk/">trunk</a><span class="sp">/&nbsp;</span><a href="/p/processing/source/browse/trunk/processing/">processing</a><span class="sp">/&nbsp;</span><a href="/p/processing/source/browse/trunk/processing/core/">core</a><span class="sp">/&nbsp;</span><a href="/p/processing/source/browse/trunk/processing/core/src/">src</a><span class="sp">/&nbsp;</span><a href="/p/processing/source/browse/trunk/processing/core/src/processing/">processing</a><span class="sp">/&nbsp;</span><a href="/p/processing/source/browse/trunk/processing/core/src/processing/core/">core</a><span class="sp">/&nbsp;</span>PShapeSVG.java</span>
 
 

 </td>
 
 
 <td nowrap="nowrap" width="33%" align="center">
 <a href="/p/processing/source/browse/trunk/processing/core/src/processing/core/PShapeSVG.java?edit=1"
 ><img src="http://www.gstatic.com/codesite/ph/images/pencil-y14.png"
 class="edit_icon">Edit file</a>
 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/processing/source/browse/trunk/processing/core/src/processing/core/PShapeSVG.java?r=7117" title="Previous">&lsaquo;r7117</a></li>
 
 </ul>
 </td>
 
 <td class="flipper"><b>r7768</b></td>
 
 </tr></table>
 </td> 
 </tr>
</table>

<div class="fc">
 
 
 
<style type="text/css">
.undermouse span {
 background-image: url(http://www.gstatic.com/codesite/ph/images/comments.gif); }
</style>
<table class="opened" id="review_comment_area"
><tr>
<td id="nums">
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
<pre><table width="100%" id="nums_table_0"><tr id="gr_svn7768_1"

><td id="1"><a href="#1">1</a></td></tr
><tr id="gr_svn7768_2"

><td id="2"><a href="#2">2</a></td></tr
><tr id="gr_svn7768_3"

><td id="3"><a href="#3">3</a></td></tr
><tr id="gr_svn7768_4"

><td id="4"><a href="#4">4</a></td></tr
><tr id="gr_svn7768_5"

><td id="5"><a href="#5">5</a></td></tr
><tr id="gr_svn7768_6"

><td id="6"><a href="#6">6</a></td></tr
><tr id="gr_svn7768_7"

><td id="7"><a href="#7">7</a></td></tr
><tr id="gr_svn7768_8"

><td id="8"><a href="#8">8</a></td></tr
><tr id="gr_svn7768_9"

><td id="9"><a href="#9">9</a></td></tr
><tr id="gr_svn7768_10"

><td id="10"><a href="#10">10</a></td></tr
><tr id="gr_svn7768_11"

><td id="11"><a href="#11">11</a></td></tr
><tr id="gr_svn7768_12"

><td id="12"><a href="#12">12</a></td></tr
><tr id="gr_svn7768_13"

><td id="13"><a href="#13">13</a></td></tr
><tr id="gr_svn7768_14"

><td id="14"><a href="#14">14</a></td></tr
><tr id="gr_svn7768_15"

><td id="15"><a href="#15">15</a></td></tr
><tr id="gr_svn7768_16"

><td id="16"><a href="#16">16</a></td></tr
><tr id="gr_svn7768_17"

><td id="17"><a href="#17">17</a></td></tr
><tr id="gr_svn7768_18"

><td id="18"><a href="#18">18</a></td></tr
><tr id="gr_svn7768_19"

><td id="19"><a href="#19">19</a></td></tr
><tr id="gr_svn7768_20"

><td id="20"><a href="#20">20</a></td></tr
><tr id="gr_svn7768_21"

><td id="21"><a href="#21">21</a></td></tr
><tr id="gr_svn7768_22"

><td id="22"><a href="#22">22</a></td></tr
><tr id="gr_svn7768_23"

><td id="23"><a href="#23">23</a></td></tr
><tr id="gr_svn7768_24"

><td id="24"><a href="#24">24</a></td></tr
><tr id="gr_svn7768_25"

><td id="25"><a href="#25">25</a></td></tr
><tr id="gr_svn7768_26"

><td id="26"><a href="#26">26</a></td></tr
><tr id="gr_svn7768_27"

><td id="27"><a href="#27">27</a></td></tr
><tr id="gr_svn7768_28"

><td id="28"><a href="#28">28</a></td></tr
><tr id="gr_svn7768_29"

><td id="29"><a href="#29">29</a></td></tr
><tr id="gr_svn7768_30"

><td id="30"><a href="#30">30</a></td></tr
><tr id="gr_svn7768_31"

><td id="31"><a href="#31">31</a></td></tr
><tr id="gr_svn7768_32"

><td id="32"><a href="#32">32</a></td></tr
><tr id="gr_svn7768_33"

><td id="33"><a href="#33">33</a></td></tr
><tr id="gr_svn7768_34"

><td id="34"><a href="#34">34</a></td></tr
><tr id="gr_svn7768_35"

><td id="35"><a href="#35">35</a></td></tr
><tr id="gr_svn7768_36"

><td id="36"><a href="#36">36</a></td></tr
><tr id="gr_svn7768_37"

><td id="37"><a href="#37">37</a></td></tr
><tr id="gr_svn7768_38"

><td id="38"><a href="#38">38</a></td></tr
><tr id="gr_svn7768_39"

><td id="39"><a href="#39">39</a></td></tr
><tr id="gr_svn7768_40"

><td id="40"><a href="#40">40</a></td></tr
><tr id="gr_svn7768_41"

><td id="41"><a href="#41">41</a></td></tr
><tr id="gr_svn7768_42"

><td id="42"><a href="#42">42</a></td></tr
><tr id="gr_svn7768_43"

><td id="43"><a href="#43">43</a></td></tr
><tr id="gr_svn7768_44"

><td id="44"><a href="#44">44</a></td></tr
><tr id="gr_svn7768_45"

><td id="45"><a href="#45">45</a></td></tr
><tr id="gr_svn7768_46"

><td id="46"><a href="#46">46</a></td></tr
><tr id="gr_svn7768_47"

><td id="47"><a href="#47">47</a></td></tr
><tr id="gr_svn7768_48"

><td id="48"><a href="#48">48</a></td></tr
><tr id="gr_svn7768_49"

><td id="49"><a href="#49">49</a></td></tr
><tr id="gr_svn7768_50"

><td id="50"><a href="#50">50</a></td></tr
><tr id="gr_svn7768_51"

><td id="51"><a href="#51">51</a></td></tr
><tr id="gr_svn7768_52"

><td id="52"><a href="#52">52</a></td></tr
><tr id="gr_svn7768_53"

><td id="53"><a href="#53">53</a></td></tr
><tr id="gr_svn7768_54"

><td id="54"><a href="#54">54</a></td></tr
><tr id="gr_svn7768_55"

><td id="55"><a href="#55">55</a></td></tr
><tr id="gr_svn7768_56"

><td id="56"><a href="#56">56</a></td></tr
><tr id="gr_svn7768_57"

><td id="57"><a href="#57">57</a></td></tr
><tr id="gr_svn7768_58"

><td id="58"><a href="#58">58</a></td></tr
><tr id="gr_svn7768_59"

><td id="59"><a href="#59">59</a></td></tr
><tr id="gr_svn7768_60"

><td id="60"><a href="#60">60</a></td></tr
><tr id="gr_svn7768_61"

><td id="61"><a href="#61">61</a></td></tr
><tr id="gr_svn7768_62"

><td id="62"><a href="#62">62</a></td></tr
><tr id="gr_svn7768_63"

><td id="63"><a href="#63">63</a></td></tr
><tr id="gr_svn7768_64"

><td id="64"><a href="#64">64</a></td></tr
><tr id="gr_svn7768_65"

><td id="65"><a href="#65">65</a></td></tr
><tr id="gr_svn7768_66"

><td id="66"><a href="#66">66</a></td></tr
><tr id="gr_svn7768_67"

><td id="67"><a href="#67">67</a></td></tr
><tr id="gr_svn7768_68"

><td id="68"><a href="#68">68</a></td></tr
><tr id="gr_svn7768_69"

><td id="69"><a href="#69">69</a></td></tr
><tr id="gr_svn7768_70"

><td id="70"><a href="#70">70</a></td></tr
><tr id="gr_svn7768_71"

><td id="71"><a href="#71">71</a></td></tr
><tr id="gr_svn7768_72"

><td id="72"><a href="#72">72</a></td></tr
><tr id="gr_svn7768_73"

><td id="73"><a href="#73">73</a></td></tr
><tr id="gr_svn7768_74"

><td id="74"><a href="#74">74</a></td></tr
><tr id="gr_svn7768_75"

><td id="75"><a href="#75">75</a></td></tr
><tr id="gr_svn7768_76"

><td id="76"><a href="#76">76</a></td></tr
><tr id="gr_svn7768_77"

><td id="77"><a href="#77">77</a></td></tr
><tr id="gr_svn7768_78"

><td id="78"><a href="#78">78</a></td></tr
><tr id="gr_svn7768_79"

><td id="79"><a href="#79">79</a></td></tr
><tr id="gr_svn7768_80"

><td id="80"><a href="#80">80</a></td></tr
><tr id="gr_svn7768_81"

><td id="81"><a href="#81">81</a></td></tr
><tr id="gr_svn7768_82"

><td id="82"><a href="#82">82</a></td></tr
><tr id="gr_svn7768_83"

><td id="83"><a href="#83">83</a></td></tr
><tr id="gr_svn7768_84"

><td id="84"><a href="#84">84</a></td></tr
><tr id="gr_svn7768_85"

><td id="85"><a href="#85">85</a></td></tr
><tr id="gr_svn7768_86"

><td id="86"><a href="#86">86</a></td></tr
><tr id="gr_svn7768_87"

><td id="87"><a href="#87">87</a></td></tr
><tr id="gr_svn7768_88"

><td id="88"><a href="#88">88</a></td></tr
><tr id="gr_svn7768_89"

><td id="89"><a href="#89">89</a></td></tr
><tr id="gr_svn7768_90"

><td id="90"><a href="#90">90</a></td></tr
><tr id="gr_svn7768_91"

><td id="91"><a href="#91">91</a></td></tr
><tr id="gr_svn7768_92"

><td id="92"><a href="#92">92</a></td></tr
><tr id="gr_svn7768_93"

><td id="93"><a href="#93">93</a></td></tr
><tr id="gr_svn7768_94"

><td id="94"><a href="#94">94</a></td></tr
><tr id="gr_svn7768_95"

><td id="95"><a href="#95">95</a></td></tr
><tr id="gr_svn7768_96"

><td id="96"><a href="#96">96</a></td></tr
><tr id="gr_svn7768_97"

><td id="97"><a href="#97">97</a></td></tr
><tr id="gr_svn7768_98"

><td id="98"><a href="#98">98</a></td></tr
><tr id="gr_svn7768_99"

><td id="99"><a href="#99">99</a></td></tr
><tr id="gr_svn7768_100"

><td id="100"><a href="#100">100</a></td></tr
><tr id="gr_svn7768_101"

><td id="101"><a href="#101">101</a></td></tr
><tr id="gr_svn7768_102"

><td id="102"><a href="#102">102</a></td></tr
><tr id="gr_svn7768_103"

><td id="103"><a href="#103">103</a></td></tr
><tr id="gr_svn7768_104"

><td id="104"><a href="#104">104</a></td></tr
><tr id="gr_svn7768_105"

><td id="105"><a href="#105">105</a></td></tr
><tr id="gr_svn7768_106"

><td id="106"><a href="#106">106</a></td></tr
><tr id="gr_svn7768_107"

><td id="107"><a href="#107">107</a></td></tr
><tr id="gr_svn7768_108"

><td id="108"><a href="#108">108</a></td></tr
><tr id="gr_svn7768_109"

><td id="109"><a href="#109">109</a></td></tr
><tr id="gr_svn7768_110"

><td id="110"><a href="#110">110</a></td></tr
><tr id="gr_svn7768_111"

><td id="111"><a href="#111">111</a></td></tr
><tr id="gr_svn7768_112"

><td id="112"><a href="#112">112</a></td></tr
><tr id="gr_svn7768_113"

><td id="113"><a href="#113">113</a></td></tr
><tr id="gr_svn7768_114"

><td id="114"><a href="#114">114</a></td></tr
><tr id="gr_svn7768_115"

><td id="115"><a href="#115">115</a></td></tr
><tr id="gr_svn7768_116"

><td id="116"><a href="#116">116</a></td></tr
><tr id="gr_svn7768_117"

><td id="117"><a href="#117">117</a></td></tr
><tr id="gr_svn7768_118"

><td id="118"><a href="#118">118</a></td></tr
><tr id="gr_svn7768_119"

><td id="119"><a href="#119">119</a></td></tr
><tr id="gr_svn7768_120"

><td id="120"><a href="#120">120</a></td></tr
><tr id="gr_svn7768_121"

><td id="121"><a href="#121">121</a></td></tr
><tr id="gr_svn7768_122"

><td id="122"><a href="#122">122</a></td></tr
><tr id="gr_svn7768_123"

><td id="123"><a href="#123">123</a></td></tr
><tr id="gr_svn7768_124"

><td id="124"><a href="#124">124</a></td></tr
><tr id="gr_svn7768_125"

><td id="125"><a href="#125">125</a></td></tr
><tr id="gr_svn7768_126"

><td id="126"><a href="#126">126</a></td></tr
><tr id="gr_svn7768_127"

><td id="127"><a href="#127">127</a></td></tr
><tr id="gr_svn7768_128"

><td id="128"><a href="#128">128</a></td></tr
><tr id="gr_svn7768_129"

><td id="129"><a href="#129">129</a></td></tr
><tr id="gr_svn7768_130"

><td id="130"><a href="#130">130</a></td></tr
><tr id="gr_svn7768_131"

><td id="131"><a href="#131">131</a></td></tr
><tr id="gr_svn7768_132"

><td id="132"><a href="#132">132</a></td></tr
><tr id="gr_svn7768_133"

><td id="133"><a href="#133">133</a></td></tr
><tr id="gr_svn7768_134"

><td id="134"><a href="#134">134</a></td></tr
><tr id="gr_svn7768_135"

><td id="135"><a href="#135">135</a></td></tr
><tr id="gr_svn7768_136"

><td id="136"><a href="#136">136</a></td></tr
><tr id="gr_svn7768_137"

><td id="137"><a href="#137">137</a></td></tr
><tr id="gr_svn7768_138"

><td id="138"><a href="#138">138</a></td></tr
><tr id="gr_svn7768_139"

><td id="139"><a href="#139">139</a></td></tr
><tr id="gr_svn7768_140"

><td id="140"><a href="#140">140</a></td></tr
><tr id="gr_svn7768_141"

><td id="141"><a href="#141">141</a></td></tr
><tr id="gr_svn7768_142"

><td id="142"><a href="#142">142</a></td></tr
><tr id="gr_svn7768_143"

><td id="143"><a href="#143">143</a></td></tr
><tr id="gr_svn7768_144"

><td id="144"><a href="#144">144</a></td></tr
><tr id="gr_svn7768_145"

><td id="145"><a href="#145">145</a></td></tr
><tr id="gr_svn7768_146"

><td id="146"><a href="#146">146</a></td></tr
><tr id="gr_svn7768_147"

><td id="147"><a href="#147">147</a></td></tr
><tr id="gr_svn7768_148"

><td id="148"><a href="#148">148</a></td></tr
><tr id="gr_svn7768_149"

><td id="149"><a href="#149">149</a></td></tr
><tr id="gr_svn7768_150"

><td id="150"><a href="#150">150</a></td></tr
><tr id="gr_svn7768_151"

><td id="151"><a href="#151">151</a></td></tr
><tr id="gr_svn7768_152"

><td id="152"><a href="#152">152</a></td></tr
><tr id="gr_svn7768_153"

><td id="153"><a href="#153">153</a></td></tr
><tr id="gr_svn7768_154"

><td id="154"><a href="#154">154</a></td></tr
><tr id="gr_svn7768_155"

><td id="155"><a href="#155">155</a></td></tr
><tr id="gr_svn7768_156"

><td id="156"><a href="#156">156</a></td></tr
><tr id="gr_svn7768_157"

><td id="157"><a href="#157">157</a></td></tr
><tr id="gr_svn7768_158"

><td id="158"><a href="#158">158</a></td></tr
><tr id="gr_svn7768_159"

><td id="159"><a href="#159">159</a></td></tr
><tr id="gr_svn7768_160"

><td id="160"><a href="#160">160</a></td></tr
><tr id="gr_svn7768_161"

><td id="161"><a href="#161">161</a></td></tr
><tr id="gr_svn7768_162"

><td id="162"><a href="#162">162</a></td></tr
><tr id="gr_svn7768_163"

><td id="163"><a href="#163">163</a></td></tr
><tr id="gr_svn7768_164"

><td id="164"><a href="#164">164</a></td></tr
><tr id="gr_svn7768_165"

><td id="165"><a href="#165">165</a></td></tr
><tr id="gr_svn7768_166"

><td id="166"><a href="#166">166</a></td></tr
><tr id="gr_svn7768_167"

><td id="167"><a href="#167">167</a></td></tr
><tr id="gr_svn7768_168"

><td id="168"><a href="#168">168</a></td></tr
><tr id="gr_svn7768_169"

><td id="169"><a href="#169">169</a></td></tr
><tr id="gr_svn7768_170"

><td id="170"><a href="#170">170</a></td></tr
><tr id="gr_svn7768_171"

><td id="171"><a href="#171">171</a></td></tr
><tr id="gr_svn7768_172"

><td id="172"><a href="#172">172</a></td></tr
><tr id="gr_svn7768_173"

><td id="173"><a href="#173">173</a></td></tr
><tr id="gr_svn7768_174"

><td id="174"><a href="#174">174</a></td></tr
><tr id="gr_svn7768_175"

><td id="175"><a href="#175">175</a></td></tr
><tr id="gr_svn7768_176"

><td id="176"><a href="#176">176</a></td></tr
><tr id="gr_svn7768_177"

><td id="177"><a href="#177">177</a></td></tr
><tr id="gr_svn7768_178"

><td id="178"><a href="#178">178</a></td></tr
><tr id="gr_svn7768_179"

><td id="179"><a href="#179">179</a></td></tr
><tr id="gr_svn7768_180"

><td id="180"><a href="#180">180</a></td></tr
><tr id="gr_svn7768_181"

><td id="181"><a href="#181">181</a></td></tr
><tr id="gr_svn7768_182"

><td id="182"><a href="#182">182</a></td></tr
><tr id="gr_svn7768_183"

><td id="183"><a href="#183">183</a></td></tr
><tr id="gr_svn7768_184"

><td id="184"><a href="#184">184</a></td></tr
><tr id="gr_svn7768_185"

><td id="185"><a href="#185">185</a></td></tr
><tr id="gr_svn7768_186"

><td id="186"><a href="#186">186</a></td></tr
><tr id="gr_svn7768_187"

><td id="187"><a href="#187">187</a></td></tr
><tr id="gr_svn7768_188"

><td id="188"><a href="#188">188</a></td></tr
><tr id="gr_svn7768_189"

><td id="189"><a href="#189">189</a></td></tr
><tr id="gr_svn7768_190"

><td id="190"><a href="#190">190</a></td></tr
><tr id="gr_svn7768_191"

><td id="191"><a href="#191">191</a></td></tr
><tr id="gr_svn7768_192"

><td id="192"><a href="#192">192</a></td></tr
><tr id="gr_svn7768_193"

><td id="193"><a href="#193">193</a></td></tr
><tr id="gr_svn7768_194"

><td id="194"><a href="#194">194</a></td></tr
><tr id="gr_svn7768_195"

><td id="195"><a href="#195">195</a></td></tr
><tr id="gr_svn7768_196"

><td id="196"><a href="#196">196</a></td></tr
><tr id="gr_svn7768_197"

><td id="197"><a href="#197">197</a></td></tr
><tr id="gr_svn7768_198"

><td id="198"><a href="#198">198</a></td></tr
><tr id="gr_svn7768_199"

><td id="199"><a href="#199">199</a></td></tr
><tr id="gr_svn7768_200"

><td id="200"><a href="#200">200</a></td></tr
><tr id="gr_svn7768_201"

><td id="201"><a href="#201">201</a></td></tr
><tr id="gr_svn7768_202"

><td id="202"><a href="#202">202</a></td></tr
><tr id="gr_svn7768_203"

><td id="203"><a href="#203">203</a></td></tr
><tr id="gr_svn7768_204"

><td id="204"><a href="#204">204</a></td></tr
><tr id="gr_svn7768_205"

><td id="205"><a href="#205">205</a></td></tr
><tr id="gr_svn7768_206"

><td id="206"><a href="#206">206</a></td></tr
><tr id="gr_svn7768_207"

><td id="207"><a href="#207">207</a></td></tr
><tr id="gr_svn7768_208"

><td id="208"><a href="#208">208</a></td></tr
><tr id="gr_svn7768_209"

><td id="209"><a href="#209">209</a></td></tr
><tr id="gr_svn7768_210"

><td id="210"><a href="#210">210</a></td></tr
><tr id="gr_svn7768_211"

><td id="211"><a href="#211">211</a></td></tr
><tr id="gr_svn7768_212"

><td id="212"><a href="#212">212</a></td></tr
><tr id="gr_svn7768_213"

><td id="213"><a href="#213">213</a></td></tr
><tr id="gr_svn7768_214"

><td id="214"><a href="#214">214</a></td></tr
><tr id="gr_svn7768_215"

><td id="215"><a href="#215">215</a></td></tr
><tr id="gr_svn7768_216"

><td id="216"><a href="#216">216</a></td></tr
><tr id="gr_svn7768_217"

><td id="217"><a href="#217">217</a></td></tr
><tr id="gr_svn7768_218"

><td id="218"><a href="#218">218</a></td></tr
><tr id="gr_svn7768_219"

><td id="219"><a href="#219">219</a></td></tr
><tr id="gr_svn7768_220"

><td id="220"><a href="#220">220</a></td></tr
><tr id="gr_svn7768_221"

><td id="221"><a href="#221">221</a></td></tr
><tr id="gr_svn7768_222"

><td id="222"><a href="#222">222</a></td></tr
><tr id="gr_svn7768_223"

><td id="223"><a href="#223">223</a></td></tr
><tr id="gr_svn7768_224"

><td id="224"><a href="#224">224</a></td></tr
><tr id="gr_svn7768_225"

><td id="225"><a href="#225">225</a></td></tr
><tr id="gr_svn7768_226"

><td id="226"><a href="#226">226</a></td></tr
><tr id="gr_svn7768_227"

><td id="227"><a href="#227">227</a></td></tr
><tr id="gr_svn7768_228"

><td id="228"><a href="#228">228</a></td></tr
><tr id="gr_svn7768_229"

><td id="229"><a href="#229">229</a></td></tr
><tr id="gr_svn7768_230"

><td id="230"><a href="#230">230</a></td></tr
><tr id="gr_svn7768_231"

><td id="231"><a href="#231">231</a></td></tr
><tr id="gr_svn7768_232"

><td id="232"><a href="#232">232</a></td></tr
><tr id="gr_svn7768_233"

><td id="233"><a href="#233">233</a></td></tr
><tr id="gr_svn7768_234"

><td id="234"><a href="#234">234</a></td></tr
><tr id="gr_svn7768_235"

><td id="235"><a href="#235">235</a></td></tr
><tr id="gr_svn7768_236"

><td id="236"><a href="#236">236</a></td></tr
><tr id="gr_svn7768_237"

><td id="237"><a href="#237">237</a></td></tr
><tr id="gr_svn7768_238"

><td id="238"><a href="#238">238</a></td></tr
><tr id="gr_svn7768_239"

><td id="239"><a href="#239">239</a></td></tr
><tr id="gr_svn7768_240"

><td id="240"><a href="#240">240</a></td></tr
><tr id="gr_svn7768_241"

><td id="241"><a href="#241">241</a></td></tr
><tr id="gr_svn7768_242"

><td id="242"><a href="#242">242</a></td></tr
><tr id="gr_svn7768_243"

><td id="243"><a href="#243">243</a></td></tr
><tr id="gr_svn7768_244"

><td id="244"><a href="#244">244</a></td></tr
><tr id="gr_svn7768_245"

><td id="245"><a href="#245">245</a></td></tr
><tr id="gr_svn7768_246"

><td id="246"><a href="#246">246</a></td></tr
><tr id="gr_svn7768_247"

><td id="247"><a href="#247">247</a></td></tr
><tr id="gr_svn7768_248"

><td id="248"><a href="#248">248</a></td></tr
><tr id="gr_svn7768_249"

><td id="249"><a href="#249">249</a></td></tr
><tr id="gr_svn7768_250"

><td id="250"><a href="#250">250</a></td></tr
><tr id="gr_svn7768_251"

><td id="251"><a href="#251">251</a></td></tr
><tr id="gr_svn7768_252"

><td id="252"><a href="#252">252</a></td></tr
><tr id="gr_svn7768_253"

><td id="253"><a href="#253">253</a></td></tr
><tr id="gr_svn7768_254"

><td id="254"><a href="#254">254</a></td></tr
><tr id="gr_svn7768_255"

><td id="255"><a href="#255">255</a></td></tr
><tr id="gr_svn7768_256"

><td id="256"><a href="#256">256</a></td></tr
><tr id="gr_svn7768_257"

><td id="257"><a href="#257">257</a></td></tr
><tr id="gr_svn7768_258"

><td id="258"><a href="#258">258</a></td></tr
><tr id="gr_svn7768_259"

><td id="259"><a href="#259">259</a></td></tr
><tr id="gr_svn7768_260"

><td id="260"><a href="#260">260</a></td></tr
><tr id="gr_svn7768_261"

><td id="261"><a href="#261">261</a></td></tr
><tr id="gr_svn7768_262"

><td id="262"><a href="#262">262</a></td></tr
><tr id="gr_svn7768_263"

><td id="263"><a href="#263">263</a></td></tr
><tr id="gr_svn7768_264"

><td id="264"><a href="#264">264</a></td></tr
><tr id="gr_svn7768_265"

><td id="265"><a href="#265">265</a></td></tr
><tr id="gr_svn7768_266"

><td id="266"><a href="#266">266</a></td></tr
><tr id="gr_svn7768_267"

><td id="267"><a href="#267">267</a></td></tr
><tr id="gr_svn7768_268"

><td id="268"><a href="#268">268</a></td></tr
><tr id="gr_svn7768_269"

><td id="269"><a href="#269">269</a></td></tr
><tr id="gr_svn7768_270"

><td id="270"><a href="#270">270</a></td></tr
><tr id="gr_svn7768_271"

><td id="271"><a href="#271">271</a></td></tr
><tr id="gr_svn7768_272"

><td id="272"><a href="#272">272</a></td></tr
><tr id="gr_svn7768_273"

><td id="273"><a href="#273">273</a></td></tr
><tr id="gr_svn7768_274"

><td id="274"><a href="#274">274</a></td></tr
><tr id="gr_svn7768_275"

><td id="275"><a href="#275">275</a></td></tr
><tr id="gr_svn7768_276"

><td id="276"><a href="#276">276</a></td></tr
><tr id="gr_svn7768_277"

><td id="277"><a href="#277">277</a></td></tr
><tr id="gr_svn7768_278"

><td id="278"><a href="#278">278</a></td></tr
><tr id="gr_svn7768_279"

><td id="279"><a href="#279">279</a></td></tr
><tr id="gr_svn7768_280"

><td id="280"><a href="#280">280</a></td></tr
><tr id="gr_svn7768_281"

><td id="281"><a href="#281">281</a></td></tr
><tr id="gr_svn7768_282"

><td id="282"><a href="#282">282</a></td></tr
><tr id="gr_svn7768_283"

><td id="283"><a href="#283">283</a></td></tr
><tr id="gr_svn7768_284"

><td id="284"><a href="#284">284</a></td></tr
><tr id="gr_svn7768_285"

><td id="285"><a href="#285">285</a></td></tr
><tr id="gr_svn7768_286"

><td id="286"><a href="#286">286</a></td></tr
><tr id="gr_svn7768_287"

><td id="287"><a href="#287">287</a></td></tr
><tr id="gr_svn7768_288"

><td id="288"><a href="#288">288</a></td></tr
><tr id="gr_svn7768_289"

><td id="289"><a href="#289">289</a></td></tr
><tr id="gr_svn7768_290"

><td id="290"><a href="#290">290</a></td></tr
><tr id="gr_svn7768_291"

><td id="291"><a href="#291">291</a></td></tr
><tr id="gr_svn7768_292"

><td id="292"><a href="#292">292</a></td></tr
><tr id="gr_svn7768_293"

><td id="293"><a href="#293">293</a></td></tr
><tr id="gr_svn7768_294"

><td id="294"><a href="#294">294</a></td></tr
><tr id="gr_svn7768_295"

><td id="295"><a href="#295">295</a></td></tr
><tr id="gr_svn7768_296"

><td id="296"><a href="#296">296</a></td></tr
><tr id="gr_svn7768_297"

><td id="297"><a href="#297">297</a></td></tr
><tr id="gr_svn7768_298"

><td id="298"><a href="#298">298</a></td></tr
><tr id="gr_svn7768_299"

><td id="299"><a href="#299">299</a></td></tr
><tr id="gr_svn7768_300"

><td id="300"><a href="#300">300</a></td></tr
><tr id="gr_svn7768_301"

><td id="301"><a href="#301">301</a></td></tr
><tr id="gr_svn7768_302"

><td id="302"><a href="#302">302</a></td></tr
><tr id="gr_svn7768_303"

><td id="303"><a href="#303">303</a></td></tr
><tr id="gr_svn7768_304"

><td id="304"><a href="#304">304</a></td></tr
><tr id="gr_svn7768_305"

><td id="305"><a href="#305">305</a></td></tr
><tr id="gr_svn7768_306"

><td id="306"><a href="#306">306</a></td></tr
><tr id="gr_svn7768_307"

><td id="307"><a href="#307">307</a></td></tr
><tr id="gr_svn7768_308"

><td id="308"><a href="#308">308</a></td></tr
><tr id="gr_svn7768_309"

><td id="309"><a href="#309">309</a></td></tr
><tr id="gr_svn7768_310"

><td id="310"><a href="#310">310</a></td></tr
><tr id="gr_svn7768_311"

><td id="311"><a href="#311">311</a></td></tr
><tr id="gr_svn7768_312"

><td id="312"><a href="#312">312</a></td></tr
><tr id="gr_svn7768_313"

><td id="313"><a href="#313">313</a></td></tr
><tr id="gr_svn7768_314"

><td id="314"><a href="#314">314</a></td></tr
><tr id="gr_svn7768_315"

><td id="315"><a href="#315">315</a></td></tr
><tr id="gr_svn7768_316"

><td id="316"><a href="#316">316</a></td></tr
><tr id="gr_svn7768_317"

><td id="317"><a href="#317">317</a></td></tr
><tr id="gr_svn7768_318"

><td id="318"><a href="#318">318</a></td></tr
><tr id="gr_svn7768_319"

><td id="319"><a href="#319">319</a></td></tr
><tr id="gr_svn7768_320"

><td id="320"><a href="#320">320</a></td></tr
><tr id="gr_svn7768_321"

><td id="321"><a href="#321">321</a></td></tr
><tr id="gr_svn7768_322"

><td id="322"><a href="#322">322</a></td></tr
><tr id="gr_svn7768_323"

><td id="323"><a href="#323">323</a></td></tr
><tr id="gr_svn7768_324"

><td id="324"><a href="#324">324</a></td></tr
><tr id="gr_svn7768_325"

><td id="325"><a href="#325">325</a></td></tr
><tr id="gr_svn7768_326"

><td id="326"><a href="#326">326</a></td></tr
><tr id="gr_svn7768_327"

><td id="327"><a href="#327">327</a></td></tr
><tr id="gr_svn7768_328"

><td id="328"><a href="#328">328</a></td></tr
><tr id="gr_svn7768_329"

><td id="329"><a href="#329">329</a></td></tr
><tr id="gr_svn7768_330"

><td id="330"><a href="#330">330</a></td></tr
><tr id="gr_svn7768_331"

><td id="331"><a href="#331">331</a></td></tr
><tr id="gr_svn7768_332"

><td id="332"><a href="#332">332</a></td></tr
><tr id="gr_svn7768_333"

><td id="333"><a href="#333">333</a></td></tr
><tr id="gr_svn7768_334"

><td id="334"><a href="#334">334</a></td></tr
><tr id="gr_svn7768_335"

><td id="335"><a href="#335">335</a></td></tr
><tr id="gr_svn7768_336"

><td id="336"><a href="#336">336</a></td></tr
><tr id="gr_svn7768_337"

><td id="337"><a href="#337">337</a></td></tr
><tr id="gr_svn7768_338"

><td id="338"><a href="#338">338</a></td></tr
><tr id="gr_svn7768_339"

><td id="339"><a href="#339">339</a></td></tr
><tr id="gr_svn7768_340"

><td id="340"><a href="#340">340</a></td></tr
><tr id="gr_svn7768_341"

><td id="341"><a href="#341">341</a></td></tr
><tr id="gr_svn7768_342"

><td id="342"><a href="#342">342</a></td></tr
><tr id="gr_svn7768_343"

><td id="343"><a href="#343">343</a></td></tr
><tr id="gr_svn7768_344"

><td id="344"><a href="#344">344</a></td></tr
><tr id="gr_svn7768_345"

><td id="345"><a href="#345">345</a></td></tr
><tr id="gr_svn7768_346"

><td id="346"><a href="#346">346</a></td></tr
><tr id="gr_svn7768_347"

><td id="347"><a href="#347">347</a></td></tr
><tr id="gr_svn7768_348"

><td id="348"><a href="#348">348</a></td></tr
><tr id="gr_svn7768_349"

><td id="349"><a href="#349">349</a></td></tr
><tr id="gr_svn7768_350"

><td id="350"><a href="#350">350</a></td></tr
><tr id="gr_svn7768_351"

><td id="351"><a href="#351">351</a></td></tr
><tr id="gr_svn7768_352"

><td id="352"><a href="#352">352</a></td></tr
><tr id="gr_svn7768_353"

><td id="353"><a href="#353">353</a></td></tr
><tr id="gr_svn7768_354"

><td id="354"><a href="#354">354</a></td></tr
><tr id="gr_svn7768_355"

><td id="355"><a href="#355">355</a></td></tr
><tr id="gr_svn7768_356"

><td id="356"><a href="#356">356</a></td></tr
><tr id="gr_svn7768_357"

><td id="357"><a href="#357">357</a></td></tr
><tr id="gr_svn7768_358"

><td id="358"><a href="#358">358</a></td></tr
><tr id="gr_svn7768_359"

><td id="359"><a href="#359">359</a></td></tr
><tr id="gr_svn7768_360"

><td id="360"><a href="#360">360</a></td></tr
><tr id="gr_svn7768_361"

><td id="361"><a href="#361">361</a></td></tr
><tr id="gr_svn7768_362"

><td id="362"><a href="#362">362</a></td></tr
><tr id="gr_svn7768_363"

><td id="363"><a href="#363">363</a></td></tr
><tr id="gr_svn7768_364"

><td id="364"><a href="#364">364</a></td></tr
><tr id="gr_svn7768_365"

><td id="365"><a href="#365">365</a></td></tr
><tr id="gr_svn7768_366"

><td id="366"><a href="#366">366</a></td></tr
><tr id="gr_svn7768_367"

><td id="367"><a href="#367">367</a></td></tr
><tr id="gr_svn7768_368"

><td id="368"><a href="#368">368</a></td></tr
><tr id="gr_svn7768_369"

><td id="369"><a href="#369">369</a></td></tr
><tr id="gr_svn7768_370"

><td id="370"><a href="#370">370</a></td></tr
><tr id="gr_svn7768_371"

><td id="371"><a href="#371">371</a></td></tr
><tr id="gr_svn7768_372"

><td id="372"><a href="#372">372</a></td></tr
><tr id="gr_svn7768_373"

><td id="373"><a href="#373">373</a></td></tr
><tr id="gr_svn7768_374"

><td id="374"><a href="#374">374</a></td></tr
><tr id="gr_svn7768_375"

><td id="375"><a href="#375">375</a></td></tr
><tr id="gr_svn7768_376"

><td id="376"><a href="#376">376</a></td></tr
><tr id="gr_svn7768_377"

><td id="377"><a href="#377">377</a></td></tr
><tr id="gr_svn7768_378"

><td id="378"><a href="#378">378</a></td></tr
><tr id="gr_svn7768_379"

><td id="379"><a href="#379">379</a></td></tr
><tr id="gr_svn7768_380"

><td id="380"><a href="#380">380</a></td></tr
><tr id="gr_svn7768_381"

><td id="381"><a href="#381">381</a></td></tr
><tr id="gr_svn7768_382"

><td id="382"><a href="#382">382</a></td></tr
><tr id="gr_svn7768_383"

><td id="383"><a href="#383">383</a></td></tr
><tr id="gr_svn7768_384"

><td id="384"><a href="#384">384</a></td></tr
><tr id="gr_svn7768_385"

><td id="385"><a href="#385">385</a></td></tr
><tr id="gr_svn7768_386"

><td id="386"><a href="#386">386</a></td></tr
><tr id="gr_svn7768_387"

><td id="387"><a href="#387">387</a></td></tr
><tr id="gr_svn7768_388"

><td id="388"><a href="#388">388</a></td></tr
><tr id="gr_svn7768_389"

><td id="389"><a href="#389">389</a></td></tr
><tr id="gr_svn7768_390"

><td id="390"><a href="#390">390</a></td></tr
><tr id="gr_svn7768_391"

><td id="391"><a href="#391">391</a></td></tr
><tr id="gr_svn7768_392"

><td id="392"><a href="#392">392</a></td></tr
><tr id="gr_svn7768_393"

><td id="393"><a href="#393">393</a></td></tr
><tr id="gr_svn7768_394"

><td id="394"><a href="#394">394</a></td></tr
><tr id="gr_svn7768_395"

><td id="395"><a href="#395">395</a></td></tr
><tr id="gr_svn7768_396"

><td id="396"><a href="#396">396</a></td></tr
><tr id="gr_svn7768_397"

><td id="397"><a href="#397">397</a></td></tr
><tr id="gr_svn7768_398"

><td id="398"><a href="#398">398</a></td></tr
><tr id="gr_svn7768_399"

><td id="399"><a href="#399">399</a></td></tr
><tr id="gr_svn7768_400"

><td id="400"><a href="#400">400</a></td></tr
><tr id="gr_svn7768_401"

><td id="401"><a href="#401">401</a></td></tr
><tr id="gr_svn7768_402"

><td id="402"><a href="#402">402</a></td></tr
><tr id="gr_svn7768_403"

><td id="403"><a href="#403">403</a></td></tr
><tr id="gr_svn7768_404"

><td id="404"><a href="#404">404</a></td></tr
><tr id="gr_svn7768_405"

><td id="405"><a href="#405">405</a></td></tr
><tr id="gr_svn7768_406"

><td id="406"><a href="#406">406</a></td></tr
><tr id="gr_svn7768_407"

><td id="407"><a href="#407">407</a></td></tr
><tr id="gr_svn7768_408"

><td id="408"><a href="#408">408</a></td></tr
><tr id="gr_svn7768_409"

><td id="409"><a href="#409">409</a></td></tr
><tr id="gr_svn7768_410"

><td id="410"><a href="#410">410</a></td></tr
><tr id="gr_svn7768_411"

><td id="411"><a href="#411">411</a></td></tr
><tr id="gr_svn7768_412"

><td id="412"><a href="#412">412</a></td></tr
><tr id="gr_svn7768_413"

><td id="413"><a href="#413">413</a></td></tr
><tr id="gr_svn7768_414"

><td id="414"><a href="#414">414</a></td></tr
><tr id="gr_svn7768_415"

><td id="415"><a href="#415">415</a></td></tr
><tr id="gr_svn7768_416"

><td id="416"><a href="#416">416</a></td></tr
><tr id="gr_svn7768_417"

><td id="417"><a href="#417">417</a></td></tr
><tr id="gr_svn7768_418"

><td id="418"><a href="#418">418</a></td></tr
><tr id="gr_svn7768_419"

><td id="419"><a href="#419">419</a></td></tr
><tr id="gr_svn7768_420"

><td id="420"><a href="#420">420</a></td></tr
><tr id="gr_svn7768_421"

><td id="421"><a href="#421">421</a></td></tr
><tr id="gr_svn7768_422"

><td id="422"><a href="#422">422</a></td></tr
><tr id="gr_svn7768_423"

><td id="423"><a href="#423">423</a></td></tr
><tr id="gr_svn7768_424"

><td id="424"><a href="#424">424</a></td></tr
><tr id="gr_svn7768_425"

><td id="425"><a href="#425">425</a></td></tr
><tr id="gr_svn7768_426"

><td id="426"><a href="#426">426</a></td></tr
><tr id="gr_svn7768_427"

><td id="427"><a href="#427">427</a></td></tr
><tr id="gr_svn7768_428"

><td id="428"><a href="#428">428</a></td></tr
><tr id="gr_svn7768_429"

><td id="429"><a href="#429">429</a></td></tr
><tr id="gr_svn7768_430"

><td id="430"><a href="#430">430</a></td></tr
><tr id="gr_svn7768_431"

><td id="431"><a href="#431">431</a></td></tr
><tr id="gr_svn7768_432"

><td id="432"><a href="#432">432</a></td></tr
><tr id="gr_svn7768_433"

><td id="433"><a href="#433">433</a></td></tr
><tr id="gr_svn7768_434"

><td id="434"><a href="#434">434</a></td></tr
><tr id="gr_svn7768_435"

><td id="435"><a href="#435">435</a></td></tr
><tr id="gr_svn7768_436"

><td id="436"><a href="#436">436</a></td></tr
><tr id="gr_svn7768_437"

><td id="437"><a href="#437">437</a></td></tr
><tr id="gr_svn7768_438"

><td id="438"><a href="#438">438</a></td></tr
><tr id="gr_svn7768_439"

><td id="439"><a href="#439">439</a></td></tr
><tr id="gr_svn7768_440"

><td id="440"><a href="#440">440</a></td></tr
><tr id="gr_svn7768_441"

><td id="441"><a href="#441">441</a></td></tr
><tr id="gr_svn7768_442"

><td id="442"><a href="#442">442</a></td></tr
><tr id="gr_svn7768_443"

><td id="443"><a href="#443">443</a></td></tr
><tr id="gr_svn7768_444"

><td id="444"><a href="#444">444</a></td></tr
><tr id="gr_svn7768_445"

><td id="445"><a href="#445">445</a></td></tr
><tr id="gr_svn7768_446"

><td id="446"><a href="#446">446</a></td></tr
><tr id="gr_svn7768_447"

><td id="447"><a href="#447">447</a></td></tr
><tr id="gr_svn7768_448"

><td id="448"><a href="#448">448</a></td></tr
><tr id="gr_svn7768_449"

><td id="449"><a href="#449">449</a></td></tr
><tr id="gr_svn7768_450"

><td id="450"><a href="#450">450</a></td></tr
><tr id="gr_svn7768_451"

><td id="451"><a href="#451">451</a></td></tr
><tr id="gr_svn7768_452"

><td id="452"><a href="#452">452</a></td></tr
><tr id="gr_svn7768_453"

><td id="453"><a href="#453">453</a></td></tr
><tr id="gr_svn7768_454"

><td id="454"><a href="#454">454</a></td></tr
><tr id="gr_svn7768_455"

><td id="455"><a href="#455">455</a></td></tr
><tr id="gr_svn7768_456"

><td id="456"><a href="#456">456</a></td></tr
><tr id="gr_svn7768_457"

><td id="457"><a href="#457">457</a></td></tr
><tr id="gr_svn7768_458"

><td id="458"><a href="#458">458</a></td></tr
><tr id="gr_svn7768_459"

><td id="459"><a href="#459">459</a></td></tr
><tr id="gr_svn7768_460"

><td id="460"><a href="#460">460</a></td></tr
><tr id="gr_svn7768_461"

><td id="461"><a href="#461">461</a></td></tr
><tr id="gr_svn7768_462"

><td id="462"><a href="#462">462</a></td></tr
><tr id="gr_svn7768_463"

><td id="463"><a href="#463">463</a></td></tr
><tr id="gr_svn7768_464"

><td id="464"><a href="#464">464</a></td></tr
><tr id="gr_svn7768_465"

><td id="465"><a href="#465">465</a></td></tr
><tr id="gr_svn7768_466"

><td id="466"><a href="#466">466</a></td></tr
><tr id="gr_svn7768_467"

><td id="467"><a href="#467">467</a></td></tr
><tr id="gr_svn7768_468"

><td id="468"><a href="#468">468</a></td></tr
><tr id="gr_svn7768_469"

><td id="469"><a href="#469">469</a></td></tr
><tr id="gr_svn7768_470"

><td id="470"><a href="#470">470</a></td></tr
><tr id="gr_svn7768_471"

><td id="471"><a href="#471">471</a></td></tr
><tr id="gr_svn7768_472"

><td id="472"><a href="#472">472</a></td></tr
><tr id="gr_svn7768_473"

><td id="473"><a href="#473">473</a></td></tr
><tr id="gr_svn7768_474"

><td id="474"><a href="#474">474</a></td></tr
><tr id="gr_svn7768_475"

><td id="475"><a href="#475">475</a></td></tr
><tr id="gr_svn7768_476"

><td id="476"><a href="#476">476</a></td></tr
><tr id="gr_svn7768_477"

><td id="477"><a href="#477">477</a></td></tr
><tr id="gr_svn7768_478"

><td id="478"><a href="#478">478</a></td></tr
><tr id="gr_svn7768_479"

><td id="479"><a href="#479">479</a></td></tr
><tr id="gr_svn7768_480"

><td id="480"><a href="#480">480</a></td></tr
><tr id="gr_svn7768_481"

><td id="481"><a href="#481">481</a></td></tr
><tr id="gr_svn7768_482"

><td id="482"><a href="#482">482</a></td></tr
><tr id="gr_svn7768_483"

><td id="483"><a href="#483">483</a></td></tr
><tr id="gr_svn7768_484"

><td id="484"><a href="#484">484</a></td></tr
><tr id="gr_svn7768_485"

><td id="485"><a href="#485">485</a></td></tr
><tr id="gr_svn7768_486"

><td id="486"><a href="#486">486</a></td></tr
><tr id="gr_svn7768_487"

><td id="487"><a href="#487">487</a></td></tr
><tr id="gr_svn7768_488"

><td id="488"><a href="#488">488</a></td></tr
><tr id="gr_svn7768_489"

><td id="489"><a href="#489">489</a></td></tr
><tr id="gr_svn7768_490"

><td id="490"><a href="#490">490</a></td></tr
><tr id="gr_svn7768_491"

><td id="491"><a href="#491">491</a></td></tr
><tr id="gr_svn7768_492"

><td id="492"><a href="#492">492</a></td></tr
><tr id="gr_svn7768_493"

><td id="493"><a href="#493">493</a></td></tr
><tr id="gr_svn7768_494"

><td id="494"><a href="#494">494</a></td></tr
><tr id="gr_svn7768_495"

><td id="495"><a href="#495">495</a></td></tr
><tr id="gr_svn7768_496"

><td id="496"><a href="#496">496</a></td></tr
><tr id="gr_svn7768_497"

><td id="497"><a href="#497">497</a></td></tr
><tr id="gr_svn7768_498"

><td id="498"><a href="#498">498</a></td></tr
><tr id="gr_svn7768_499"

><td id="499"><a href="#499">499</a></td></tr
><tr id="gr_svn7768_500"

><td id="500"><a href="#500">500</a></td></tr
><tr id="gr_svn7768_501"

><td id="501"><a href="#501">501</a></td></tr
><tr id="gr_svn7768_502"

><td id="502"><a href="#502">502</a></td></tr
><tr id="gr_svn7768_503"

><td id="503"><a href="#503">503</a></td></tr
><tr id="gr_svn7768_504"

><td id="504"><a href="#504">504</a></td></tr
><tr id="gr_svn7768_505"

><td id="505"><a href="#505">505</a></td></tr
><tr id="gr_svn7768_506"

><td id="506"><a href="#506">506</a></td></tr
><tr id="gr_svn7768_507"

><td id="507"><a href="#507">507</a></td></tr
><tr id="gr_svn7768_508"

><td id="508"><a href="#508">508</a></td></tr
><tr id="gr_svn7768_509"

><td id="509"><a href="#509">509</a></td></tr
><tr id="gr_svn7768_510"

><td id="510"><a href="#510">510</a></td></tr
><tr id="gr_svn7768_511"

><td id="511"><a href="#511">511</a></td></tr
><tr id="gr_svn7768_512"

><td id="512"><a href="#512">512</a></td></tr
><tr id="gr_svn7768_513"

><td id="513"><a href="#513">513</a></td></tr
><tr id="gr_svn7768_514"

><td id="514"><a href="#514">514</a></td></tr
><tr id="gr_svn7768_515"

><td id="515"><a href="#515">515</a></td></tr
><tr id="gr_svn7768_516"

><td id="516"><a href="#516">516</a></td></tr
><tr id="gr_svn7768_517"

><td id="517"><a href="#517">517</a></td></tr
><tr id="gr_svn7768_518"

><td id="518"><a href="#518">518</a></td></tr
><tr id="gr_svn7768_519"

><td id="519"><a href="#519">519</a></td></tr
><tr id="gr_svn7768_520"

><td id="520"><a href="#520">520</a></td></tr
><tr id="gr_svn7768_521"

><td id="521"><a href="#521">521</a></td></tr
><tr id="gr_svn7768_522"

><td id="522"><a href="#522">522</a></td></tr
><tr id="gr_svn7768_523"

><td id="523"><a href="#523">523</a></td></tr
><tr id="gr_svn7768_524"

><td id="524"><a href="#524">524</a></td></tr
><tr id="gr_svn7768_525"

><td id="525"><a href="#525">525</a></td></tr
><tr id="gr_svn7768_526"

><td id="526"><a href="#526">526</a></td></tr
><tr id="gr_svn7768_527"

><td id="527"><a href="#527">527</a></td></tr
><tr id="gr_svn7768_528"

><td id="528"><a href="#528">528</a></td></tr
><tr id="gr_svn7768_529"

><td id="529"><a href="#529">529</a></td></tr
><tr id="gr_svn7768_530"

><td id="530"><a href="#530">530</a></td></tr
><tr id="gr_svn7768_531"

><td id="531"><a href="#531">531</a></td></tr
><tr id="gr_svn7768_532"

><td id="532"><a href="#532">532</a></td></tr
><tr id="gr_svn7768_533"

><td id="533"><a href="#533">533</a></td></tr
><tr id="gr_svn7768_534"

><td id="534"><a href="#534">534</a></td></tr
><tr id="gr_svn7768_535"

><td id="535"><a href="#535">535</a></td></tr
><tr id="gr_svn7768_536"

><td id="536"><a href="#536">536</a></td></tr
><tr id="gr_svn7768_537"

><td id="537"><a href="#537">537</a></td></tr
><tr id="gr_svn7768_538"

><td id="538"><a href="#538">538</a></td></tr
><tr id="gr_svn7768_539"

><td id="539"><a href="#539">539</a></td></tr
><tr id="gr_svn7768_540"

><td id="540"><a href="#540">540</a></td></tr
><tr id="gr_svn7768_541"

><td id="541"><a href="#541">541</a></td></tr
><tr id="gr_svn7768_542"

><td id="542"><a href="#542">542</a></td></tr
><tr id="gr_svn7768_543"

><td id="543"><a href="#543">543</a></td></tr
><tr id="gr_svn7768_544"

><td id="544"><a href="#544">544</a></td></tr
><tr id="gr_svn7768_545"

><td id="545"><a href="#545">545</a></td></tr
><tr id="gr_svn7768_546"

><td id="546"><a href="#546">546</a></td></tr
><tr id="gr_svn7768_547"

><td id="547"><a href="#547">547</a></td></tr
><tr id="gr_svn7768_548"

><td id="548"><a href="#548">548</a></td></tr
><tr id="gr_svn7768_549"

><td id="549"><a href="#549">549</a></td></tr
><tr id="gr_svn7768_550"

><td id="550"><a href="#550">550</a></td></tr
><tr id="gr_svn7768_551"

><td id="551"><a href="#551">551</a></td></tr
><tr id="gr_svn7768_552"

><td id="552"><a href="#552">552</a></td></tr
><tr id="gr_svn7768_553"

><td id="553"><a href="#553">553</a></td></tr
><tr id="gr_svn7768_554"

><td id="554"><a href="#554">554</a></td></tr
><tr id="gr_svn7768_555"

><td id="555"><a href="#555">555</a></td></tr
><tr id="gr_svn7768_556"

><td id="556"><a href="#556">556</a></td></tr
><tr id="gr_svn7768_557"

><td id="557"><a href="#557">557</a></td></tr
><tr id="gr_svn7768_558"

><td id="558"><a href="#558">558</a></td></tr
><tr id="gr_svn7768_559"

><td id="559"><a href="#559">559</a></td></tr
><tr id="gr_svn7768_560"

><td id="560"><a href="#560">560</a></td></tr
><tr id="gr_svn7768_561"

><td id="561"><a href="#561">561</a></td></tr
><tr id="gr_svn7768_562"

><td id="562"><a href="#562">562</a></td></tr
><tr id="gr_svn7768_563"

><td id="563"><a href="#563">563</a></td></tr
><tr id="gr_svn7768_564"

><td id="564"><a href="#564">564</a></td></tr
><tr id="gr_svn7768_565"

><td id="565"><a href="#565">565</a></td></tr
><tr id="gr_svn7768_566"

><td id="566"><a href="#566">566</a></td></tr
><tr id="gr_svn7768_567"

><td id="567"><a href="#567">567</a></td></tr
><tr id="gr_svn7768_568"

><td id="568"><a href="#568">568</a></td></tr
><tr id="gr_svn7768_569"

><td id="569"><a href="#569">569</a></td></tr
><tr id="gr_svn7768_570"

><td id="570"><a href="#570">570</a></td></tr
><tr id="gr_svn7768_571"

><td id="571"><a href="#571">571</a></td></tr
><tr id="gr_svn7768_572"

><td id="572"><a href="#572">572</a></td></tr
><tr id="gr_svn7768_573"

><td id="573"><a href="#573">573</a></td></tr
><tr id="gr_svn7768_574"

><td id="574"><a href="#574">574</a></td></tr
><tr id="gr_svn7768_575"

><td id="575"><a href="#575">575</a></td></tr
><tr id="gr_svn7768_576"

><td id="576"><a href="#576">576</a></td></tr
><tr id="gr_svn7768_577"

><td id="577"><a href="#577">577</a></td></tr
><tr id="gr_svn7768_578"

><td id="578"><a href="#578">578</a></td></tr
><tr id="gr_svn7768_579"

><td id="579"><a href="#579">579</a></td></tr
><tr id="gr_svn7768_580"

><td id="580"><a href="#580">580</a></td></tr
><tr id="gr_svn7768_581"

><td id="581"><a href="#581">581</a></td></tr
><tr id="gr_svn7768_582"

><td id="582"><a href="#582">582</a></td></tr
><tr id="gr_svn7768_583"

><td id="583"><a href="#583">583</a></td></tr
><tr id="gr_svn7768_584"

><td id="584"><a href="#584">584</a></td></tr
><tr id="gr_svn7768_585"

><td id="585"><a href="#585">585</a></td></tr
><tr id="gr_svn7768_586"

><td id="586"><a href="#586">586</a></td></tr
><tr id="gr_svn7768_587"

><td id="587"><a href="#587">587</a></td></tr
><tr id="gr_svn7768_588"

><td id="588"><a href="#588">588</a></td></tr
><tr id="gr_svn7768_589"

><td id="589"><a href="#589">589</a></td></tr
><tr id="gr_svn7768_590"

><td id="590"><a href="#590">590</a></td></tr
><tr id="gr_svn7768_591"

><td id="591"><a href="#591">591</a></td></tr
><tr id="gr_svn7768_592"

><td id="592"><a href="#592">592</a></td></tr
><tr id="gr_svn7768_593"

><td id="593"><a href="#593">593</a></td></tr
><tr id="gr_svn7768_594"

><td id="594"><a href="#594">594</a></td></tr
><tr id="gr_svn7768_595"

><td id="595"><a href="#595">595</a></td></tr
><tr id="gr_svn7768_596"

><td id="596"><a href="#596">596</a></td></tr
><tr id="gr_svn7768_597"

><td id="597"><a href="#597">597</a></td></tr
><tr id="gr_svn7768_598"

><td id="598"><a href="#598">598</a></td></tr
><tr id="gr_svn7768_599"

><td id="599"><a href="#599">599</a></td></tr
><tr id="gr_svn7768_600"

><td id="600"><a href="#600">600</a></td></tr
><tr id="gr_svn7768_601"

><td id="601"><a href="#601">601</a></td></tr
><tr id="gr_svn7768_602"

><td id="602"><a href="#602">602</a></td></tr
><tr id="gr_svn7768_603"

><td id="603"><a href="#603">603</a></td></tr
><tr id="gr_svn7768_604"

><td id="604"><a href="#604">604</a></td></tr
><tr id="gr_svn7768_605"

><td id="605"><a href="#605">605</a></td></tr
><tr id="gr_svn7768_606"

><td id="606"><a href="#606">606</a></td></tr
><tr id="gr_svn7768_607"

><td id="607"><a href="#607">607</a></td></tr
><tr id="gr_svn7768_608"

><td id="608"><a href="#608">608</a></td></tr
><tr id="gr_svn7768_609"

><td id="609"><a href="#609">609</a></td></tr
><tr id="gr_svn7768_610"

><td id="610"><a href="#610">610</a></td></tr
><tr id="gr_svn7768_611"

><td id="611"><a href="#611">611</a></td></tr
><tr id="gr_svn7768_612"

><td id="612"><a href="#612">612</a></td></tr
><tr id="gr_svn7768_613"

><td id="613"><a href="#613">613</a></td></tr
><tr id="gr_svn7768_614"

><td id="614"><a href="#614">614</a></td></tr
><tr id="gr_svn7768_615"

><td id="615"><a href="#615">615</a></td></tr
><tr id="gr_svn7768_616"

><td id="616"><a href="#616">616</a></td></tr
><tr id="gr_svn7768_617"

><td id="617"><a href="#617">617</a></td></tr
><tr id="gr_svn7768_618"

><td id="618"><a href="#618">618</a></td></tr
><tr id="gr_svn7768_619"

><td id="619"><a href="#619">619</a></td></tr
><tr id="gr_svn7768_620"

><td id="620"><a href="#620">620</a></td></tr
><tr id="gr_svn7768_621"

><td id="621"><a href="#621">621</a></td></tr
><tr id="gr_svn7768_622"

><td id="622"><a href="#622">622</a></td></tr
><tr id="gr_svn7768_623"

><td id="623"><a href="#623">623</a></td></tr
><tr id="gr_svn7768_624"

><td id="624"><a href="#624">624</a></td></tr
><tr id="gr_svn7768_625"

><td id="625"><a href="#625">625</a></td></tr
><tr id="gr_svn7768_626"

><td id="626"><a href="#626">626</a></td></tr
><tr id="gr_svn7768_627"

><td id="627"><a href="#627">627</a></td></tr
><tr id="gr_svn7768_628"

><td id="628"><a href="#628">628</a></td></tr
><tr id="gr_svn7768_629"

><td id="629"><a href="#629">629</a></td></tr
><tr id="gr_svn7768_630"

><td id="630"><a href="#630">630</a></td></tr
><tr id="gr_svn7768_631"

><td id="631"><a href="#631">631</a></td></tr
><tr id="gr_svn7768_632"

><td id="632"><a href="#632">632</a></td></tr
><tr id="gr_svn7768_633"

><td id="633"><a href="#633">633</a></td></tr
><tr id="gr_svn7768_634"

><td id="634"><a href="#634">634</a></td></tr
><tr id="gr_svn7768_635"

><td id="635"><a href="#635">635</a></td></tr
><tr id="gr_svn7768_636"

><td id="636"><a href="#636">636</a></td></tr
><tr id="gr_svn7768_637"

><td id="637"><a href="#637">637</a></td></tr
><tr id="gr_svn7768_638"

><td id="638"><a href="#638">638</a></td></tr
><tr id="gr_svn7768_639"

><td id="639"><a href="#639">639</a></td></tr
><tr id="gr_svn7768_640"

><td id="640"><a href="#640">640</a></td></tr
><tr id="gr_svn7768_641"

><td id="641"><a href="#641">641</a></td></tr
><tr id="gr_svn7768_642"

><td id="642"><a href="#642">642</a></td></tr
><tr id="gr_svn7768_643"

><td id="643"><a href="#643">643</a></td></tr
><tr id="gr_svn7768_644"

><td id="644"><a href="#644">644</a></td></tr
><tr id="gr_svn7768_645"

><td id="645"><a href="#645">645</a></td></tr
><tr id="gr_svn7768_646"

><td id="646"><a href="#646">646</a></td></tr
><tr id="gr_svn7768_647"

><td id="647"><a href="#647">647</a></td></tr
><tr id="gr_svn7768_648"

><td id="648"><a href="#648">648</a></td></tr
><tr id="gr_svn7768_649"

><td id="649"><a href="#649">649</a></td></tr
><tr id="gr_svn7768_650"

><td id="650"><a href="#650">650</a></td></tr
><tr id="gr_svn7768_651"

><td id="651"><a href="#651">651</a></td></tr
><tr id="gr_svn7768_652"

><td id="652"><a href="#652">652</a></td></tr
><tr id="gr_svn7768_653"

><td id="653"><a href="#653">653</a></td></tr
><tr id="gr_svn7768_654"

><td id="654"><a href="#654">654</a></td></tr
><tr id="gr_svn7768_655"

><td id="655"><a href="#655">655</a></td></tr
><tr id="gr_svn7768_656"

><td id="656"><a href="#656">656</a></td></tr
><tr id="gr_svn7768_657"

><td id="657"><a href="#657">657</a></td></tr
><tr id="gr_svn7768_658"

><td id="658"><a href="#658">658</a></td></tr
><tr id="gr_svn7768_659"

><td id="659"><a href="#659">659</a></td></tr
><tr id="gr_svn7768_660"

><td id="660"><a href="#660">660</a></td></tr
><tr id="gr_svn7768_661"

><td id="661"><a href="#661">661</a></td></tr
><tr id="gr_svn7768_662"

><td id="662"><a href="#662">662</a></td></tr
><tr id="gr_svn7768_663"

><td id="663"><a href="#663">663</a></td></tr
><tr id="gr_svn7768_664"

><td id="664"><a href="#664">664</a></td></tr
><tr id="gr_svn7768_665"

><td id="665"><a href="#665">665</a></td></tr
><tr id="gr_svn7768_666"

><td id="666"><a href="#666">666</a></td></tr
><tr id="gr_svn7768_667"

><td id="667"><a href="#667">667</a></td></tr
><tr id="gr_svn7768_668"

><td id="668"><a href="#668">668</a></td></tr
><tr id="gr_svn7768_669"

><td id="669"><a href="#669">669</a></td></tr
><tr id="gr_svn7768_670"

><td id="670"><a href="#670">670</a></td></tr
><tr id="gr_svn7768_671"

><td id="671"><a href="#671">671</a></td></tr
><tr id="gr_svn7768_672"

><td id="672"><a href="#672">672</a></td></tr
><tr id="gr_svn7768_673"

><td id="673"><a href="#673">673</a></td></tr
><tr id="gr_svn7768_674"

><td id="674"><a href="#674">674</a></td></tr
><tr id="gr_svn7768_675"

><td id="675"><a href="#675">675</a></td></tr
><tr id="gr_svn7768_676"

><td id="676"><a href="#676">676</a></td></tr
><tr id="gr_svn7768_677"

><td id="677"><a href="#677">677</a></td></tr
><tr id="gr_svn7768_678"

><td id="678"><a href="#678">678</a></td></tr
><tr id="gr_svn7768_679"

><td id="679"><a href="#679">679</a></td></tr
><tr id="gr_svn7768_680"

><td id="680"><a href="#680">680</a></td></tr
><tr id="gr_svn7768_681"

><td id="681"><a href="#681">681</a></td></tr
><tr id="gr_svn7768_682"

><td id="682"><a href="#682">682</a></td></tr
><tr id="gr_svn7768_683"

><td id="683"><a href="#683">683</a></td></tr
><tr id="gr_svn7768_684"

><td id="684"><a href="#684">684</a></td></tr
><tr id="gr_svn7768_685"

><td id="685"><a href="#685">685</a></td></tr
><tr id="gr_svn7768_686"

><td id="686"><a href="#686">686</a></td></tr
><tr id="gr_svn7768_687"

><td id="687"><a href="#687">687</a></td></tr
><tr id="gr_svn7768_688"

><td id="688"><a href="#688">688</a></td></tr
><tr id="gr_svn7768_689"

><td id="689"><a href="#689">689</a></td></tr
><tr id="gr_svn7768_690"

><td id="690"><a href="#690">690</a></td></tr
><tr id="gr_svn7768_691"

><td id="691"><a href="#691">691</a></td></tr
><tr id="gr_svn7768_692"

><td id="692"><a href="#692">692</a></td></tr
><tr id="gr_svn7768_693"

><td id="693"><a href="#693">693</a></td></tr
><tr id="gr_svn7768_694"

><td id="694"><a href="#694">694</a></td></tr
><tr id="gr_svn7768_695"

><td id="695"><a href="#695">695</a></td></tr
><tr id="gr_svn7768_696"

><td id="696"><a href="#696">696</a></td></tr
><tr id="gr_svn7768_697"

><td id="697"><a href="#697">697</a></td></tr
><tr id="gr_svn7768_698"

><td id="698"><a href="#698">698</a></td></tr
><tr id="gr_svn7768_699"

><td id="699"><a href="#699">699</a></td></tr
><tr id="gr_svn7768_700"

><td id="700"><a href="#700">700</a></td></tr
><tr id="gr_svn7768_701"

><td id="701"><a href="#701">701</a></td></tr
><tr id="gr_svn7768_702"

><td id="702"><a href="#702">702</a></td></tr
><tr id="gr_svn7768_703"

><td id="703"><a href="#703">703</a></td></tr
><tr id="gr_svn7768_704"

><td id="704"><a href="#704">704</a></td></tr
><tr id="gr_svn7768_705"

><td id="705"><a href="#705">705</a></td></tr
><tr id="gr_svn7768_706"

><td id="706"><a href="#706">706</a></td></tr
><tr id="gr_svn7768_707"

><td id="707"><a href="#707">707</a></td></tr
><tr id="gr_svn7768_708"

><td id="708"><a href="#708">708</a></td></tr
><tr id="gr_svn7768_709"

><td id="709"><a href="#709">709</a></td></tr
><tr id="gr_svn7768_710"

><td id="710"><a href="#710">710</a></td></tr
><tr id="gr_svn7768_711"

><td id="711"><a href="#711">711</a></td></tr
><tr id="gr_svn7768_712"

><td id="712"><a href="#712">712</a></td></tr
><tr id="gr_svn7768_713"

><td id="713"><a href="#713">713</a></td></tr
><tr id="gr_svn7768_714"

><td id="714"><a href="#714">714</a></td></tr
><tr id="gr_svn7768_715"

><td id="715"><a href="#715">715</a></td></tr
><tr id="gr_svn7768_716"

><td id="716"><a href="#716">716</a></td></tr
><tr id="gr_svn7768_717"

><td id="717"><a href="#717">717</a></td></tr
><tr id="gr_svn7768_718"

><td id="718"><a href="#718">718</a></td></tr
><tr id="gr_svn7768_719"

><td id="719"><a href="#719">719</a></td></tr
><tr id="gr_svn7768_720"

><td id="720"><a href="#720">720</a></td></tr
><tr id="gr_svn7768_721"

><td id="721"><a href="#721">721</a></td></tr
><tr id="gr_svn7768_722"

><td id="722"><a href="#722">722</a></td></tr
><tr id="gr_svn7768_723"

><td id="723"><a href="#723">723</a></td></tr
><tr id="gr_svn7768_724"

><td id="724"><a href="#724">724</a></td></tr
><tr id="gr_svn7768_725"

><td id="725"><a href="#725">725</a></td></tr
><tr id="gr_svn7768_726"

><td id="726"><a href="#726">726</a></td></tr
><tr id="gr_svn7768_727"

><td id="727"><a href="#727">727</a></td></tr
><tr id="gr_svn7768_728"

><td id="728"><a href="#728">728</a></td></tr
><tr id="gr_svn7768_729"

><td id="729"><a href="#729">729</a></td></tr
><tr id="gr_svn7768_730"

><td id="730"><a href="#730">730</a></td></tr
><tr id="gr_svn7768_731"

><td id="731"><a href="#731">731</a></td></tr
><tr id="gr_svn7768_732"

><td id="732"><a href="#732">732</a></td></tr
><tr id="gr_svn7768_733"

><td id="733"><a href="#733">733</a></td></tr
><tr id="gr_svn7768_734"

><td id="734"><a href="#734">734</a></td></tr
><tr id="gr_svn7768_735"

><td id="735"><a href="#735">735</a></td></tr
><tr id="gr_svn7768_736"

><td id="736"><a href="#736">736</a></td></tr
><tr id="gr_svn7768_737"

><td id="737"><a href="#737">737</a></td></tr
><tr id="gr_svn7768_738"

><td id="738"><a href="#738">738</a></td></tr
><tr id="gr_svn7768_739"

><td id="739"><a href="#739">739</a></td></tr
><tr id="gr_svn7768_740"

><td id="740"><a href="#740">740</a></td></tr
><tr id="gr_svn7768_741"

><td id="741"><a href="#741">741</a></td></tr
><tr id="gr_svn7768_742"

><td id="742"><a href="#742">742</a></td></tr
><tr id="gr_svn7768_743"

><td id="743"><a href="#743">743</a></td></tr
><tr id="gr_svn7768_744"

><td id="744"><a href="#744">744</a></td></tr
><tr id="gr_svn7768_745"

><td id="745"><a href="#745">745</a></td></tr
><tr id="gr_svn7768_746"

><td id="746"><a href="#746">746</a></td></tr
><tr id="gr_svn7768_747"

><td id="747"><a href="#747">747</a></td></tr
><tr id="gr_svn7768_748"

><td id="748"><a href="#748">748</a></td></tr
><tr id="gr_svn7768_749"

><td id="749"><a href="#749">749</a></td></tr
><tr id="gr_svn7768_750"

><td id="750"><a href="#750">750</a></td></tr
><tr id="gr_svn7768_751"

><td id="751"><a href="#751">751</a></td></tr
><tr id="gr_svn7768_752"

><td id="752"><a href="#752">752</a></td></tr
><tr id="gr_svn7768_753"

><td id="753"><a href="#753">753</a></td></tr
><tr id="gr_svn7768_754"

><td id="754"><a href="#754">754</a></td></tr
><tr id="gr_svn7768_755"

><td id="755"><a href="#755">755</a></td></tr
><tr id="gr_svn7768_756"

><td id="756"><a href="#756">756</a></td></tr
><tr id="gr_svn7768_757"

><td id="757"><a href="#757">757</a></td></tr
><tr id="gr_svn7768_758"

><td id="758"><a href="#758">758</a></td></tr
><tr id="gr_svn7768_759"

><td id="759"><a href="#759">759</a></td></tr
><tr id="gr_svn7768_760"

><td id="760"><a href="#760">760</a></td></tr
><tr id="gr_svn7768_761"

><td id="761"><a href="#761">761</a></td></tr
><tr id="gr_svn7768_762"

><td id="762"><a href="#762">762</a></td></tr
><tr id="gr_svn7768_763"

><td id="763"><a href="#763">763</a></td></tr
><tr id="gr_svn7768_764"

><td id="764"><a href="#764">764</a></td></tr
><tr id="gr_svn7768_765"

><td id="765"><a href="#765">765</a></td></tr
><tr id="gr_svn7768_766"

><td id="766"><a href="#766">766</a></td></tr
><tr id="gr_svn7768_767"

><td id="767"><a href="#767">767</a></td></tr
><tr id="gr_svn7768_768"

><td id="768"><a href="#768">768</a></td></tr
><tr id="gr_svn7768_769"

><td id="769"><a href="#769">769</a></td></tr
><tr id="gr_svn7768_770"

><td id="770"><a href="#770">770</a></td></tr
><tr id="gr_svn7768_771"

><td id="771"><a href="#771">771</a></td></tr
><tr id="gr_svn7768_772"

><td id="772"><a href="#772">772</a></td></tr
><tr id="gr_svn7768_773"

><td id="773"><a href="#773">773</a></td></tr
><tr id="gr_svn7768_774"

><td id="774"><a href="#774">774</a></td></tr
><tr id="gr_svn7768_775"

><td id="775"><a href="#775">775</a></td></tr
><tr id="gr_svn7768_776"

><td id="776"><a href="#776">776</a></td></tr
><tr id="gr_svn7768_777"

><td id="777"><a href="#777">777</a></td></tr
><tr id="gr_svn7768_778"

><td id="778"><a href="#778">778</a></td></tr
><tr id="gr_svn7768_779"

><td id="779"><a href="#779">779</a></td></tr
><tr id="gr_svn7768_780"

><td id="780"><a href="#780">780</a></td></tr
><tr id="gr_svn7768_781"

><td id="781"><a href="#781">781</a></td></tr
><tr id="gr_svn7768_782"

><td id="782"><a href="#782">782</a></td></tr
><tr id="gr_svn7768_783"

><td id="783"><a href="#783">783</a></td></tr
><tr id="gr_svn7768_784"

><td id="784"><a href="#784">784</a></td></tr
><tr id="gr_svn7768_785"

><td id="785"><a href="#785">785</a></td></tr
><tr id="gr_svn7768_786"

><td id="786"><a href="#786">786</a></td></tr
><tr id="gr_svn7768_787"

><td id="787"><a href="#787">787</a></td></tr
><tr id="gr_svn7768_788"

><td id="788"><a href="#788">788</a></td></tr
><tr id="gr_svn7768_789"

><td id="789"><a href="#789">789</a></td></tr
><tr id="gr_svn7768_790"

><td id="790"><a href="#790">790</a></td></tr
><tr id="gr_svn7768_791"

><td id="791"><a href="#791">791</a></td></tr
><tr id="gr_svn7768_792"

><td id="792"><a href="#792">792</a></td></tr
><tr id="gr_svn7768_793"

><td id="793"><a href="#793">793</a></td></tr
><tr id="gr_svn7768_794"

><td id="794"><a href="#794">794</a></td></tr
><tr id="gr_svn7768_795"

><td id="795"><a href="#795">795</a></td></tr
><tr id="gr_svn7768_796"

><td id="796"><a href="#796">796</a></td></tr
><tr id="gr_svn7768_797"

><td id="797"><a href="#797">797</a></td></tr
><tr id="gr_svn7768_798"

><td id="798"><a href="#798">798</a></td></tr
><tr id="gr_svn7768_799"

><td id="799"><a href="#799">799</a></td></tr
><tr id="gr_svn7768_800"

><td id="800"><a href="#800">800</a></td></tr
><tr id="gr_svn7768_801"

><td id="801"><a href="#801">801</a></td></tr
><tr id="gr_svn7768_802"

><td id="802"><a href="#802">802</a></td></tr
><tr id="gr_svn7768_803"

><td id="803"><a href="#803">803</a></td></tr
><tr id="gr_svn7768_804"

><td id="804"><a href="#804">804</a></td></tr
><tr id="gr_svn7768_805"

><td id="805"><a href="#805">805</a></td></tr
><tr id="gr_svn7768_806"

><td id="806"><a href="#806">806</a></td></tr
><tr id="gr_svn7768_807"

><td id="807"><a href="#807">807</a></td></tr
><tr id="gr_svn7768_808"

><td id="808"><a href="#808">808</a></td></tr
><tr id="gr_svn7768_809"

><td id="809"><a href="#809">809</a></td></tr
><tr id="gr_svn7768_810"

><td id="810"><a href="#810">810</a></td></tr
><tr id="gr_svn7768_811"

><td id="811"><a href="#811">811</a></td></tr
><tr id="gr_svn7768_812"

><td id="812"><a href="#812">812</a></td></tr
><tr id="gr_svn7768_813"

><td id="813"><a href="#813">813</a></td></tr
><tr id="gr_svn7768_814"

><td id="814"><a href="#814">814</a></td></tr
><tr id="gr_svn7768_815"

><td id="815"><a href="#815">815</a></td></tr
><tr id="gr_svn7768_816"

><td id="816"><a href="#816">816</a></td></tr
><tr id="gr_svn7768_817"

><td id="817"><a href="#817">817</a></td></tr
><tr id="gr_svn7768_818"

><td id="818"><a href="#818">818</a></td></tr
><tr id="gr_svn7768_819"

><td id="819"><a href="#819">819</a></td></tr
><tr id="gr_svn7768_820"

><td id="820"><a href="#820">820</a></td></tr
><tr id="gr_svn7768_821"

><td id="821"><a href="#821">821</a></td></tr
><tr id="gr_svn7768_822"

><td id="822"><a href="#822">822</a></td></tr
><tr id="gr_svn7768_823"

><td id="823"><a href="#823">823</a></td></tr
><tr id="gr_svn7768_824"

><td id="824"><a href="#824">824</a></td></tr
><tr id="gr_svn7768_825"

><td id="825"><a href="#825">825</a></td></tr
><tr id="gr_svn7768_826"

><td id="826"><a href="#826">826</a></td></tr
><tr id="gr_svn7768_827"

><td id="827"><a href="#827">827</a></td></tr
><tr id="gr_svn7768_828"

><td id="828"><a href="#828">828</a></td></tr
><tr id="gr_svn7768_829"

><td id="829"><a href="#829">829</a></td></tr
><tr id="gr_svn7768_830"

><td id="830"><a href="#830">830</a></td></tr
><tr id="gr_svn7768_831"

><td id="831"><a href="#831">831</a></td></tr
><tr id="gr_svn7768_832"

><td id="832"><a href="#832">832</a></td></tr
><tr id="gr_svn7768_833"

><td id="833"><a href="#833">833</a></td></tr
><tr id="gr_svn7768_834"

><td id="834"><a href="#834">834</a></td></tr
><tr id="gr_svn7768_835"

><td id="835"><a href="#835">835</a></td></tr
><tr id="gr_svn7768_836"

><td id="836"><a href="#836">836</a></td></tr
><tr id="gr_svn7768_837"

><td id="837"><a href="#837">837</a></td></tr
><tr id="gr_svn7768_838"

><td id="838"><a href="#838">838</a></td></tr
><tr id="gr_svn7768_839"

><td id="839"><a href="#839">839</a></td></tr
><tr id="gr_svn7768_840"

><td id="840"><a href="#840">840</a></td></tr
><tr id="gr_svn7768_841"

><td id="841"><a href="#841">841</a></td></tr
><tr id="gr_svn7768_842"

><td id="842"><a href="#842">842</a></td></tr
><tr id="gr_svn7768_843"

><td id="843"><a href="#843">843</a></td></tr
><tr id="gr_svn7768_844"

><td id="844"><a href="#844">844</a></td></tr
><tr id="gr_svn7768_845"

><td id="845"><a href="#845">845</a></td></tr
><tr id="gr_svn7768_846"

><td id="846"><a href="#846">846</a></td></tr
><tr id="gr_svn7768_847"

><td id="847"><a href="#847">847</a></td></tr
><tr id="gr_svn7768_848"

><td id="848"><a href="#848">848</a></td></tr
><tr id="gr_svn7768_849"

><td id="849"><a href="#849">849</a></td></tr
><tr id="gr_svn7768_850"

><td id="850"><a href="#850">850</a></td></tr
><tr id="gr_svn7768_851"

><td id="851"><a href="#851">851</a></td></tr
><tr id="gr_svn7768_852"

><td id="852"><a href="#852">852</a></td></tr
><tr id="gr_svn7768_853"

><td id="853"><a href="#853">853</a></td></tr
><tr id="gr_svn7768_854"

><td id="854"><a href="#854">854</a></td></tr
><tr id="gr_svn7768_855"

><td id="855"><a href="#855">855</a></td></tr
><tr id="gr_svn7768_856"

><td id="856"><a href="#856">856</a></td></tr
><tr id="gr_svn7768_857"

><td id="857"><a href="#857">857</a></td></tr
><tr id="gr_svn7768_858"

><td id="858"><a href="#858">858</a></td></tr
><tr id="gr_svn7768_859"

><td id="859"><a href="#859">859</a></td></tr
><tr id="gr_svn7768_860"

><td id="860"><a href="#860">860</a></td></tr
><tr id="gr_svn7768_861"

><td id="861"><a href="#861">861</a></td></tr
><tr id="gr_svn7768_862"

><td id="862"><a href="#862">862</a></td></tr
><tr id="gr_svn7768_863"

><td id="863"><a href="#863">863</a></td></tr
><tr id="gr_svn7768_864"

><td id="864"><a href="#864">864</a></td></tr
><tr id="gr_svn7768_865"

><td id="865"><a href="#865">865</a></td></tr
><tr id="gr_svn7768_866"

><td id="866"><a href="#866">866</a></td></tr
><tr id="gr_svn7768_867"

><td id="867"><a href="#867">867</a></td></tr
><tr id="gr_svn7768_868"

><td id="868"><a href="#868">868</a></td></tr
><tr id="gr_svn7768_869"

><td id="869"><a href="#869">869</a></td></tr
><tr id="gr_svn7768_870"

><td id="870"><a href="#870">870</a></td></tr
><tr id="gr_svn7768_871"

><td id="871"><a href="#871">871</a></td></tr
><tr id="gr_svn7768_872"

><td id="872"><a href="#872">872</a></td></tr
><tr id="gr_svn7768_873"

><td id="873"><a href="#873">873</a></td></tr
><tr id="gr_svn7768_874"

><td id="874"><a href="#874">874</a></td></tr
><tr id="gr_svn7768_875"

><td id="875"><a href="#875">875</a></td></tr
><tr id="gr_svn7768_876"

><td id="876"><a href="#876">876</a></td></tr
><tr id="gr_svn7768_877"

><td id="877"><a href="#877">877</a></td></tr
><tr id="gr_svn7768_878"

><td id="878"><a href="#878">878</a></td></tr
><tr id="gr_svn7768_879"

><td id="879"><a href="#879">879</a></td></tr
><tr id="gr_svn7768_880"

><td id="880"><a href="#880">880</a></td></tr
><tr id="gr_svn7768_881"

><td id="881"><a href="#881">881</a></td></tr
><tr id="gr_svn7768_882"

><td id="882"><a href="#882">882</a></td></tr
><tr id="gr_svn7768_883"

><td id="883"><a href="#883">883</a></td></tr
><tr id="gr_svn7768_884"

><td id="884"><a href="#884">884</a></td></tr
><tr id="gr_svn7768_885"

><td id="885"><a href="#885">885</a></td></tr
><tr id="gr_svn7768_886"

><td id="886"><a href="#886">886</a></td></tr
><tr id="gr_svn7768_887"

><td id="887"><a href="#887">887</a></td></tr
><tr id="gr_svn7768_888"

><td id="888"><a href="#888">888</a></td></tr
><tr id="gr_svn7768_889"

><td id="889"><a href="#889">889</a></td></tr
><tr id="gr_svn7768_890"

><td id="890"><a href="#890">890</a></td></tr
><tr id="gr_svn7768_891"

><td id="891"><a href="#891">891</a></td></tr
><tr id="gr_svn7768_892"

><td id="892"><a href="#892">892</a></td></tr
><tr id="gr_svn7768_893"

><td id="893"><a href="#893">893</a></td></tr
><tr id="gr_svn7768_894"

><td id="894"><a href="#894">894</a></td></tr
><tr id="gr_svn7768_895"

><td id="895"><a href="#895">895</a></td></tr
><tr id="gr_svn7768_896"

><td id="896"><a href="#896">896</a></td></tr
><tr id="gr_svn7768_897"

><td id="897"><a href="#897">897</a></td></tr
><tr id="gr_svn7768_898"

><td id="898"><a href="#898">898</a></td></tr
><tr id="gr_svn7768_899"

><td id="899"><a href="#899">899</a></td></tr
><tr id="gr_svn7768_900"

><td id="900"><a href="#900">900</a></td></tr
><tr id="gr_svn7768_901"

><td id="901"><a href="#901">901</a></td></tr
><tr id="gr_svn7768_902"

><td id="902"><a href="#902">902</a></td></tr
><tr id="gr_svn7768_903"

><td id="903"><a href="#903">903</a></td></tr
><tr id="gr_svn7768_904"

><td id="904"><a href="#904">904</a></td></tr
><tr id="gr_svn7768_905"

><td id="905"><a href="#905">905</a></td></tr
><tr id="gr_svn7768_906"

><td id="906"><a href="#906">906</a></td></tr
><tr id="gr_svn7768_907"

><td id="907"><a href="#907">907</a></td></tr
><tr id="gr_svn7768_908"

><td id="908"><a href="#908">908</a></td></tr
><tr id="gr_svn7768_909"

><td id="909"><a href="#909">909</a></td></tr
><tr id="gr_svn7768_910"

><td id="910"><a href="#910">910</a></td></tr
><tr id="gr_svn7768_911"

><td id="911"><a href="#911">911</a></td></tr
><tr id="gr_svn7768_912"

><td id="912"><a href="#912">912</a></td></tr
><tr id="gr_svn7768_913"

><td id="913"><a href="#913">913</a></td></tr
><tr id="gr_svn7768_914"

><td id="914"><a href="#914">914</a></td></tr
><tr id="gr_svn7768_915"

><td id="915"><a href="#915">915</a></td></tr
><tr id="gr_svn7768_916"

><td id="916"><a href="#916">916</a></td></tr
><tr id="gr_svn7768_917"

><td id="917"><a href="#917">917</a></td></tr
><tr id="gr_svn7768_918"

><td id="918"><a href="#918">918</a></td></tr
><tr id="gr_svn7768_919"

><td id="919"><a href="#919">919</a></td></tr
><tr id="gr_svn7768_920"

><td id="920"><a href="#920">920</a></td></tr
><tr id="gr_svn7768_921"

><td id="921"><a href="#921">921</a></td></tr
><tr id="gr_svn7768_922"

><td id="922"><a href="#922">922</a></td></tr
><tr id="gr_svn7768_923"

><td id="923"><a href="#923">923</a></td></tr
><tr id="gr_svn7768_924"

><td id="924"><a href="#924">924</a></td></tr
><tr id="gr_svn7768_925"

><td id="925"><a href="#925">925</a></td></tr
><tr id="gr_svn7768_926"

><td id="926"><a href="#926">926</a></td></tr
><tr id="gr_svn7768_927"

><td id="927"><a href="#927">927</a></td></tr
><tr id="gr_svn7768_928"

><td id="928"><a href="#928">928</a></td></tr
><tr id="gr_svn7768_929"

><td id="929"><a href="#929">929</a></td></tr
><tr id="gr_svn7768_930"

><td id="930"><a href="#930">930</a></td></tr
><tr id="gr_svn7768_931"

><td id="931"><a href="#931">931</a></td></tr
><tr id="gr_svn7768_932"

><td id="932"><a href="#932">932</a></td></tr
><tr id="gr_svn7768_933"

><td id="933"><a href="#933">933</a></td></tr
><tr id="gr_svn7768_934"

><td id="934"><a href="#934">934</a></td></tr
><tr id="gr_svn7768_935"

><td id="935"><a href="#935">935</a></td></tr
><tr id="gr_svn7768_936"

><td id="936"><a href="#936">936</a></td></tr
><tr id="gr_svn7768_937"

><td id="937"><a href="#937">937</a></td></tr
><tr id="gr_svn7768_938"

><td id="938"><a href="#938">938</a></td></tr
><tr id="gr_svn7768_939"

><td id="939"><a href="#939">939</a></td></tr
><tr id="gr_svn7768_940"

><td id="940"><a href="#940">940</a></td></tr
><tr id="gr_svn7768_941"

><td id="941"><a href="#941">941</a></td></tr
><tr id="gr_svn7768_942"

><td id="942"><a href="#942">942</a></td></tr
><tr id="gr_svn7768_943"

><td id="943"><a href="#943">943</a></td></tr
><tr id="gr_svn7768_944"

><td id="944"><a href="#944">944</a></td></tr
><tr id="gr_svn7768_945"

><td id="945"><a href="#945">945</a></td></tr
><tr id="gr_svn7768_946"

><td id="946"><a href="#946">946</a></td></tr
><tr id="gr_svn7768_947"

><td id="947"><a href="#947">947</a></td></tr
><tr id="gr_svn7768_948"

><td id="948"><a href="#948">948</a></td></tr
><tr id="gr_svn7768_949"

><td id="949"><a href="#949">949</a></td></tr
><tr id="gr_svn7768_950"

><td id="950"><a href="#950">950</a></td></tr
><tr id="gr_svn7768_951"

><td id="951"><a href="#951">951</a></td></tr
><tr id="gr_svn7768_952"

><td id="952"><a href="#952">952</a></td></tr
><tr id="gr_svn7768_953"

><td id="953"><a href="#953">953</a></td></tr
><tr id="gr_svn7768_954"

><td id="954"><a href="#954">954</a></td></tr
><tr id="gr_svn7768_955"

><td id="955"><a href="#955">955</a></td></tr
><tr id="gr_svn7768_956"

><td id="956"><a href="#956">956</a></td></tr
><tr id="gr_svn7768_957"

><td id="957"><a href="#957">957</a></td></tr
><tr id="gr_svn7768_958"

><td id="958"><a href="#958">958</a></td></tr
><tr id="gr_svn7768_959"

><td id="959"><a href="#959">959</a></td></tr
><tr id="gr_svn7768_960"

><td id="960"><a href="#960">960</a></td></tr
><tr id="gr_svn7768_961"

><td id="961"><a href="#961">961</a></td></tr
><tr id="gr_svn7768_962"

><td id="962"><a href="#962">962</a></td></tr
><tr id="gr_svn7768_963"

><td id="963"><a href="#963">963</a></td></tr
><tr id="gr_svn7768_964"

><td id="964"><a href="#964">964</a></td></tr
><tr id="gr_svn7768_965"

><td id="965"><a href="#965">965</a></td></tr
><tr id="gr_svn7768_966"

><td id="966"><a href="#966">966</a></td></tr
><tr id="gr_svn7768_967"

><td id="967"><a href="#967">967</a></td></tr
><tr id="gr_svn7768_968"

><td id="968"><a href="#968">968</a></td></tr
><tr id="gr_svn7768_969"

><td id="969"><a href="#969">969</a></td></tr
><tr id="gr_svn7768_970"

><td id="970"><a href="#970">970</a></td></tr
><tr id="gr_svn7768_971"

><td id="971"><a href="#971">971</a></td></tr
><tr id="gr_svn7768_972"

><td id="972"><a href="#972">972</a></td></tr
><tr id="gr_svn7768_973"

><td id="973"><a href="#973">973</a></td></tr
><tr id="gr_svn7768_974"

><td id="974"><a href="#974">974</a></td></tr
><tr id="gr_svn7768_975"

><td id="975"><a href="#975">975</a></td></tr
><tr id="gr_svn7768_976"

><td id="976"><a href="#976">976</a></td></tr
><tr id="gr_svn7768_977"

><td id="977"><a href="#977">977</a></td></tr
><tr id="gr_svn7768_978"

><td id="978"><a href="#978">978</a></td></tr
><tr id="gr_svn7768_979"

><td id="979"><a href="#979">979</a></td></tr
><tr id="gr_svn7768_980"

><td id="980"><a href="#980">980</a></td></tr
><tr id="gr_svn7768_981"

><td id="981"><a href="#981">981</a></td></tr
><tr id="gr_svn7768_982"

><td id="982"><a href="#982">982</a></td></tr
><tr id="gr_svn7768_983"

><td id="983"><a href="#983">983</a></td></tr
><tr id="gr_svn7768_984"

><td id="984"><a href="#984">984</a></td></tr
><tr id="gr_svn7768_985"

><td id="985"><a href="#985">985</a></td></tr
><tr id="gr_svn7768_986"

><td id="986"><a href="#986">986</a></td></tr
><tr id="gr_svn7768_987"

><td id="987"><a href="#987">987</a></td></tr
><tr id="gr_svn7768_988"

><td id="988"><a href="#988">988</a></td></tr
><tr id="gr_svn7768_989"

><td id="989"><a href="#989">989</a></td></tr
><tr id="gr_svn7768_990"

><td id="990"><a href="#990">990</a></td></tr
><tr id="gr_svn7768_991"

><td id="991"><a href="#991">991</a></td></tr
><tr id="gr_svn7768_992"

><td id="992"><a href="#992">992</a></td></tr
><tr id="gr_svn7768_993"

><td id="993"><a href="#993">993</a></td></tr
><tr id="gr_svn7768_994"

><td id="994"><a href="#994">994</a></td></tr
><tr id="gr_svn7768_995"

><td id="995"><a href="#995">995</a></td></tr
><tr id="gr_svn7768_996"

><td id="996"><a href="#996">996</a></td></tr
><tr id="gr_svn7768_997"

><td id="997"><a href="#997">997</a></td></tr
><tr id="gr_svn7768_998"

><td id="998"><a href="#998">998</a></td></tr
><tr id="gr_svn7768_999"

><td id="999"><a href="#999">999</a></td></tr
><tr id="gr_svn7768_1000"

><td id="1000"><a href="#1000">1000</a></td></tr
><tr id="gr_svn7768_1001"

><td id="1001"><a href="#1001">1001</a></td></tr
><tr id="gr_svn7768_1002"

><td id="1002"><a href="#1002">1002</a></td></tr
><tr id="gr_svn7768_1003"

><td id="1003"><a href="#1003">1003</a></td></tr
><tr id="gr_svn7768_1004"

><td id="1004"><a href="#1004">1004</a></td></tr
><tr id="gr_svn7768_1005"

><td id="1005"><a href="#1005">1005</a></td></tr
><tr id="gr_svn7768_1006"

><td id="1006"><a href="#1006">1006</a></td></tr
><tr id="gr_svn7768_1007"

><td id="1007"><a href="#1007">1007</a></td></tr
><tr id="gr_svn7768_1008"

><td id="1008"><a href="#1008">1008</a></td></tr
><tr id="gr_svn7768_1009"

><td id="1009"><a href="#1009">1009</a></td></tr
><tr id="gr_svn7768_1010"

><td id="1010"><a href="#1010">1010</a></td></tr
><tr id="gr_svn7768_1011"

><td id="1011"><a href="#1011">1011</a></td></tr
><tr id="gr_svn7768_1012"

><td id="1012"><a href="#1012">1012</a></td></tr
><tr id="gr_svn7768_1013"

><td id="1013"><a href="#1013">1013</a></td></tr
><tr id="gr_svn7768_1014"

><td id="1014"><a href="#1014">1014</a></td></tr
><tr id="gr_svn7768_1015"

><td id="1015"><a href="#1015">1015</a></td></tr
><tr id="gr_svn7768_1016"

><td id="1016"><a href="#1016">1016</a></td></tr
><tr id="gr_svn7768_1017"

><td id="1017"><a href="#1017">1017</a></td></tr
><tr id="gr_svn7768_1018"

><td id="1018"><a href="#1018">1018</a></td></tr
><tr id="gr_svn7768_1019"

><td id="1019"><a href="#1019">1019</a></td></tr
><tr id="gr_svn7768_1020"

><td id="1020"><a href="#1020">1020</a></td></tr
><tr id="gr_svn7768_1021"

><td id="1021"><a href="#1021">1021</a></td></tr
><tr id="gr_svn7768_1022"

><td id="1022"><a href="#1022">1022</a></td></tr
><tr id="gr_svn7768_1023"

><td id="1023"><a href="#1023">1023</a></td></tr
><tr id="gr_svn7768_1024"

><td id="1024"><a href="#1024">1024</a></td></tr
><tr id="gr_svn7768_1025"

><td id="1025"><a href="#1025">1025</a></td></tr
><tr id="gr_svn7768_1026"

><td id="1026"><a href="#1026">1026</a></td></tr
><tr id="gr_svn7768_1027"

><td id="1027"><a href="#1027">1027</a></td></tr
><tr id="gr_svn7768_1028"

><td id="1028"><a href="#1028">1028</a></td></tr
><tr id="gr_svn7768_1029"

><td id="1029"><a href="#1029">1029</a></td></tr
><tr id="gr_svn7768_1030"

><td id="1030"><a href="#1030">1030</a></td></tr
><tr id="gr_svn7768_1031"

><td id="1031"><a href="#1031">1031</a></td></tr
><tr id="gr_svn7768_1032"

><td id="1032"><a href="#1032">1032</a></td></tr
><tr id="gr_svn7768_1033"

><td id="1033"><a href="#1033">1033</a></td></tr
><tr id="gr_svn7768_1034"

><td id="1034"><a href="#1034">1034</a></td></tr
><tr id="gr_svn7768_1035"

><td id="1035"><a href="#1035">1035</a></td></tr
><tr id="gr_svn7768_1036"

><td id="1036"><a href="#1036">1036</a></td></tr
><tr id="gr_svn7768_1037"

><td id="1037"><a href="#1037">1037</a></td></tr
><tr id="gr_svn7768_1038"

><td id="1038"><a href="#1038">1038</a></td></tr
><tr id="gr_svn7768_1039"

><td id="1039"><a href="#1039">1039</a></td></tr
><tr id="gr_svn7768_1040"

><td id="1040"><a href="#1040">1040</a></td></tr
><tr id="gr_svn7768_1041"

><td id="1041"><a href="#1041">1041</a></td></tr
><tr id="gr_svn7768_1042"

><td id="1042"><a href="#1042">1042</a></td></tr
><tr id="gr_svn7768_1043"

><td id="1043"><a href="#1043">1043</a></td></tr
><tr id="gr_svn7768_1044"

><td id="1044"><a href="#1044">1044</a></td></tr
><tr id="gr_svn7768_1045"

><td id="1045"><a href="#1045">1045</a></td></tr
><tr id="gr_svn7768_1046"

><td id="1046"><a href="#1046">1046</a></td></tr
><tr id="gr_svn7768_1047"

><td id="1047"><a href="#1047">1047</a></td></tr
><tr id="gr_svn7768_1048"

><td id="1048"><a href="#1048">1048</a></td></tr
><tr id="gr_svn7768_1049"

><td id="1049"><a href="#1049">1049</a></td></tr
><tr id="gr_svn7768_1050"

><td id="1050"><a href="#1050">1050</a></td></tr
><tr id="gr_svn7768_1051"

><td id="1051"><a href="#1051">1051</a></td></tr
><tr id="gr_svn7768_1052"

><td id="1052"><a href="#1052">1052</a></td></tr
><tr id="gr_svn7768_1053"

><td id="1053"><a href="#1053">1053</a></td></tr
><tr id="gr_svn7768_1054"

><td id="1054"><a href="#1054">1054</a></td></tr
><tr id="gr_svn7768_1055"

><td id="1055"><a href="#1055">1055</a></td></tr
><tr id="gr_svn7768_1056"

><td id="1056"><a href="#1056">1056</a></td></tr
><tr id="gr_svn7768_1057"

><td id="1057"><a href="#1057">1057</a></td></tr
><tr id="gr_svn7768_1058"

><td id="1058"><a href="#1058">1058</a></td></tr
><tr id="gr_svn7768_1059"

><td id="1059"><a href="#1059">1059</a></td></tr
><tr id="gr_svn7768_1060"

><td id="1060"><a href="#1060">1060</a></td></tr
><tr id="gr_svn7768_1061"

><td id="1061"><a href="#1061">1061</a></td></tr
><tr id="gr_svn7768_1062"

><td id="1062"><a href="#1062">1062</a></td></tr
><tr id="gr_svn7768_1063"

><td id="1063"><a href="#1063">1063</a></td></tr
><tr id="gr_svn7768_1064"

><td id="1064"><a href="#1064">1064</a></td></tr
><tr id="gr_svn7768_1065"

><td id="1065"><a href="#1065">1065</a></td></tr
><tr id="gr_svn7768_1066"

><td id="1066"><a href="#1066">1066</a></td></tr
><tr id="gr_svn7768_1067"

><td id="1067"><a href="#1067">1067</a></td></tr
><tr id="gr_svn7768_1068"

><td id="1068"><a href="#1068">1068</a></td></tr
><tr id="gr_svn7768_1069"

><td id="1069"><a href="#1069">1069</a></td></tr
><tr id="gr_svn7768_1070"

><td id="1070"><a href="#1070">1070</a></td></tr
><tr id="gr_svn7768_1071"

><td id="1071"><a href="#1071">1071</a></td></tr
><tr id="gr_svn7768_1072"

><td id="1072"><a href="#1072">1072</a></td></tr
><tr id="gr_svn7768_1073"

><td id="1073"><a href="#1073">1073</a></td></tr
><tr id="gr_svn7768_1074"

><td id="1074"><a href="#1074">1074</a></td></tr
><tr id="gr_svn7768_1075"

><td id="1075"><a href="#1075">1075</a></td></tr
><tr id="gr_svn7768_1076"

><td id="1076"><a href="#1076">1076</a></td></tr
><tr id="gr_svn7768_1077"

><td id="1077"><a href="#1077">1077</a></td></tr
><tr id="gr_svn7768_1078"

><td id="1078"><a href="#1078">1078</a></td></tr
><tr id="gr_svn7768_1079"

><td id="1079"><a href="#1079">1079</a></td></tr
><tr id="gr_svn7768_1080"

><td id="1080"><a href="#1080">1080</a></td></tr
><tr id="gr_svn7768_1081"

><td id="1081"><a href="#1081">1081</a></td></tr
><tr id="gr_svn7768_1082"

><td id="1082"><a href="#1082">1082</a></td></tr
><tr id="gr_svn7768_1083"

><td id="1083"><a href="#1083">1083</a></td></tr
><tr id="gr_svn7768_1084"

><td id="1084"><a href="#1084">1084</a></td></tr
><tr id="gr_svn7768_1085"

><td id="1085"><a href="#1085">1085</a></td></tr
><tr id="gr_svn7768_1086"

><td id="1086"><a href="#1086">1086</a></td></tr
><tr id="gr_svn7768_1087"

><td id="1087"><a href="#1087">1087</a></td></tr
><tr id="gr_svn7768_1088"

><td id="1088"><a href="#1088">1088</a></td></tr
><tr id="gr_svn7768_1089"

><td id="1089"><a href="#1089">1089</a></td></tr
><tr id="gr_svn7768_1090"

><td id="1090"><a href="#1090">1090</a></td></tr
><tr id="gr_svn7768_1091"

><td id="1091"><a href="#1091">1091</a></td></tr
><tr id="gr_svn7768_1092"

><td id="1092"><a href="#1092">1092</a></td></tr
><tr id="gr_svn7768_1093"

><td id="1093"><a href="#1093">1093</a></td></tr
><tr id="gr_svn7768_1094"

><td id="1094"><a href="#1094">1094</a></td></tr
><tr id="gr_svn7768_1095"

><td id="1095"><a href="#1095">1095</a></td></tr
><tr id="gr_svn7768_1096"

><td id="1096"><a href="#1096">1096</a></td></tr
><tr id="gr_svn7768_1097"

><td id="1097"><a href="#1097">1097</a></td></tr
><tr id="gr_svn7768_1098"

><td id="1098"><a href="#1098">1098</a></td></tr
><tr id="gr_svn7768_1099"

><td id="1099"><a href="#1099">1099</a></td></tr
><tr id="gr_svn7768_1100"

><td id="1100"><a href="#1100">1100</a></td></tr
><tr id="gr_svn7768_1101"

><td id="1101"><a href="#1101">1101</a></td></tr
><tr id="gr_svn7768_1102"

><td id="1102"><a href="#1102">1102</a></td></tr
><tr id="gr_svn7768_1103"

><td id="1103"><a href="#1103">1103</a></td></tr
><tr id="gr_svn7768_1104"

><td id="1104"><a href="#1104">1104</a></td></tr
><tr id="gr_svn7768_1105"

><td id="1105"><a href="#1105">1105</a></td></tr
><tr id="gr_svn7768_1106"

><td id="1106"><a href="#1106">1106</a></td></tr
><tr id="gr_svn7768_1107"

><td id="1107"><a href="#1107">1107</a></td></tr
><tr id="gr_svn7768_1108"

><td id="1108"><a href="#1108">1108</a></td></tr
><tr id="gr_svn7768_1109"

><td id="1109"><a href="#1109">1109</a></td></tr
><tr id="gr_svn7768_1110"

><td id="1110"><a href="#1110">1110</a></td></tr
><tr id="gr_svn7768_1111"

><td id="1111"><a href="#1111">1111</a></td></tr
><tr id="gr_svn7768_1112"

><td id="1112"><a href="#1112">1112</a></td></tr
><tr id="gr_svn7768_1113"

><td id="1113"><a href="#1113">1113</a></td></tr
><tr id="gr_svn7768_1114"

><td id="1114"><a href="#1114">1114</a></td></tr
><tr id="gr_svn7768_1115"

><td id="1115"><a href="#1115">1115</a></td></tr
><tr id="gr_svn7768_1116"

><td id="1116"><a href="#1116">1116</a></td></tr
><tr id="gr_svn7768_1117"

><td id="1117"><a href="#1117">1117</a></td></tr
><tr id="gr_svn7768_1118"

><td id="1118"><a href="#1118">1118</a></td></tr
><tr id="gr_svn7768_1119"

><td id="1119"><a href="#1119">1119</a></td></tr
><tr id="gr_svn7768_1120"

><td id="1120"><a href="#1120">1120</a></td></tr
><tr id="gr_svn7768_1121"

><td id="1121"><a href="#1121">1121</a></td></tr
><tr id="gr_svn7768_1122"

><td id="1122"><a href="#1122">1122</a></td></tr
><tr id="gr_svn7768_1123"

><td id="1123"><a href="#1123">1123</a></td></tr
><tr id="gr_svn7768_1124"

><td id="1124"><a href="#1124">1124</a></td></tr
><tr id="gr_svn7768_1125"

><td id="1125"><a href="#1125">1125</a></td></tr
><tr id="gr_svn7768_1126"

><td id="1126"><a href="#1126">1126</a></td></tr
><tr id="gr_svn7768_1127"

><td id="1127"><a href="#1127">1127</a></td></tr
><tr id="gr_svn7768_1128"

><td id="1128"><a href="#1128">1128</a></td></tr
><tr id="gr_svn7768_1129"

><td id="1129"><a href="#1129">1129</a></td></tr
><tr id="gr_svn7768_1130"

><td id="1130"><a href="#1130">1130</a></td></tr
><tr id="gr_svn7768_1131"

><td id="1131"><a href="#1131">1131</a></td></tr
><tr id="gr_svn7768_1132"

><td id="1132"><a href="#1132">1132</a></td></tr
><tr id="gr_svn7768_1133"

><td id="1133"><a href="#1133">1133</a></td></tr
><tr id="gr_svn7768_1134"

><td id="1134"><a href="#1134">1134</a></td></tr
><tr id="gr_svn7768_1135"

><td id="1135"><a href="#1135">1135</a></td></tr
><tr id="gr_svn7768_1136"

><td id="1136"><a href="#1136">1136</a></td></tr
><tr id="gr_svn7768_1137"

><td id="1137"><a href="#1137">1137</a></td></tr
><tr id="gr_svn7768_1138"

><td id="1138"><a href="#1138">1138</a></td></tr
><tr id="gr_svn7768_1139"

><td id="1139"><a href="#1139">1139</a></td></tr
><tr id="gr_svn7768_1140"

><td id="1140"><a href="#1140">1140</a></td></tr
><tr id="gr_svn7768_1141"

><td id="1141"><a href="#1141">1141</a></td></tr
><tr id="gr_svn7768_1142"

><td id="1142"><a href="#1142">1142</a></td></tr
><tr id="gr_svn7768_1143"

><td id="1143"><a href="#1143">1143</a></td></tr
><tr id="gr_svn7768_1144"

><td id="1144"><a href="#1144">1144</a></td></tr
><tr id="gr_svn7768_1145"

><td id="1145"><a href="#1145">1145</a></td></tr
><tr id="gr_svn7768_1146"

><td id="1146"><a href="#1146">1146</a></td></tr
><tr id="gr_svn7768_1147"

><td id="1147"><a href="#1147">1147</a></td></tr
><tr id="gr_svn7768_1148"

><td id="1148"><a href="#1148">1148</a></td></tr
><tr id="gr_svn7768_1149"

><td id="1149"><a href="#1149">1149</a></td></tr
><tr id="gr_svn7768_1150"

><td id="1150"><a href="#1150">1150</a></td></tr
><tr id="gr_svn7768_1151"

><td id="1151"><a href="#1151">1151</a></td></tr
><tr id="gr_svn7768_1152"

><td id="1152"><a href="#1152">1152</a></td></tr
><tr id="gr_svn7768_1153"

><td id="1153"><a href="#1153">1153</a></td></tr
><tr id="gr_svn7768_1154"

><td id="1154"><a href="#1154">1154</a></td></tr
><tr id="gr_svn7768_1155"

><td id="1155"><a href="#1155">1155</a></td></tr
><tr id="gr_svn7768_1156"

><td id="1156"><a href="#1156">1156</a></td></tr
><tr id="gr_svn7768_1157"

><td id="1157"><a href="#1157">1157</a></td></tr
><tr id="gr_svn7768_1158"

><td id="1158"><a href="#1158">1158</a></td></tr
><tr id="gr_svn7768_1159"

><td id="1159"><a href="#1159">1159</a></td></tr
><tr id="gr_svn7768_1160"

><td id="1160"><a href="#1160">1160</a></td></tr
><tr id="gr_svn7768_1161"

><td id="1161"><a href="#1161">1161</a></td></tr
><tr id="gr_svn7768_1162"

><td id="1162"><a href="#1162">1162</a></td></tr
><tr id="gr_svn7768_1163"

><td id="1163"><a href="#1163">1163</a></td></tr
><tr id="gr_svn7768_1164"

><td id="1164"><a href="#1164">1164</a></td></tr
><tr id="gr_svn7768_1165"

><td id="1165"><a href="#1165">1165</a></td></tr
><tr id="gr_svn7768_1166"

><td id="1166"><a href="#1166">1166</a></td></tr
><tr id="gr_svn7768_1167"

><td id="1167"><a href="#1167">1167</a></td></tr
><tr id="gr_svn7768_1168"

><td id="1168"><a href="#1168">1168</a></td></tr
><tr id="gr_svn7768_1169"

><td id="1169"><a href="#1169">1169</a></td></tr
><tr id="gr_svn7768_1170"

><td id="1170"><a href="#1170">1170</a></td></tr
><tr id="gr_svn7768_1171"

><td id="1171"><a href="#1171">1171</a></td></tr
><tr id="gr_svn7768_1172"

><td id="1172"><a href="#1172">1172</a></td></tr
><tr id="gr_svn7768_1173"

><td id="1173"><a href="#1173">1173</a></td></tr
><tr id="gr_svn7768_1174"

><td id="1174"><a href="#1174">1174</a></td></tr
><tr id="gr_svn7768_1175"

><td id="1175"><a href="#1175">1175</a></td></tr
><tr id="gr_svn7768_1176"

><td id="1176"><a href="#1176">1176</a></td></tr
><tr id="gr_svn7768_1177"

><td id="1177"><a href="#1177">1177</a></td></tr
><tr id="gr_svn7768_1178"

><td id="1178"><a href="#1178">1178</a></td></tr
><tr id="gr_svn7768_1179"

><td id="1179"><a href="#1179">1179</a></td></tr
><tr id="gr_svn7768_1180"

><td id="1180"><a href="#1180">1180</a></td></tr
><tr id="gr_svn7768_1181"

><td id="1181"><a href="#1181">1181</a></td></tr
><tr id="gr_svn7768_1182"

><td id="1182"><a href="#1182">1182</a></td></tr
><tr id="gr_svn7768_1183"

><td id="1183"><a href="#1183">1183</a></td></tr
><tr id="gr_svn7768_1184"

><td id="1184"><a href="#1184">1184</a></td></tr
><tr id="gr_svn7768_1185"

><td id="1185"><a href="#1185">1185</a></td></tr
><tr id="gr_svn7768_1186"

><td id="1186"><a href="#1186">1186</a></td></tr
><tr id="gr_svn7768_1187"

><td id="1187"><a href="#1187">1187</a></td></tr
><tr id="gr_svn7768_1188"

><td id="1188"><a href="#1188">1188</a></td></tr
><tr id="gr_svn7768_1189"

><td id="1189"><a href="#1189">1189</a></td></tr
><tr id="gr_svn7768_1190"

><td id="1190"><a href="#1190">1190</a></td></tr
><tr id="gr_svn7768_1191"

><td id="1191"><a href="#1191">1191</a></td></tr
><tr id="gr_svn7768_1192"

><td id="1192"><a href="#1192">1192</a></td></tr
><tr id="gr_svn7768_1193"

><td id="1193"><a href="#1193">1193</a></td></tr
><tr id="gr_svn7768_1194"

><td id="1194"><a href="#1194">1194</a></td></tr
><tr id="gr_svn7768_1195"

><td id="1195"><a href="#1195">1195</a></td></tr
><tr id="gr_svn7768_1196"

><td id="1196"><a href="#1196">1196</a></td></tr
><tr id="gr_svn7768_1197"

><td id="1197"><a href="#1197">1197</a></td></tr
><tr id="gr_svn7768_1198"

><td id="1198"><a href="#1198">1198</a></td></tr
><tr id="gr_svn7768_1199"

><td id="1199"><a href="#1199">1199</a></td></tr
><tr id="gr_svn7768_1200"

><td id="1200"><a href="#1200">1200</a></td></tr
><tr id="gr_svn7768_1201"

><td id="1201"><a href="#1201">1201</a></td></tr
><tr id="gr_svn7768_1202"

><td id="1202"><a href="#1202">1202</a></td></tr
><tr id="gr_svn7768_1203"

><td id="1203"><a href="#1203">1203</a></td></tr
><tr id="gr_svn7768_1204"

><td id="1204"><a href="#1204">1204</a></td></tr
><tr id="gr_svn7768_1205"

><td id="1205"><a href="#1205">1205</a></td></tr
><tr id="gr_svn7768_1206"

><td id="1206"><a href="#1206">1206</a></td></tr
><tr id="gr_svn7768_1207"

><td id="1207"><a href="#1207">1207</a></td></tr
><tr id="gr_svn7768_1208"

><td id="1208"><a href="#1208">1208</a></td></tr
><tr id="gr_svn7768_1209"

><td id="1209"><a href="#1209">1209</a></td></tr
><tr id="gr_svn7768_1210"

><td id="1210"><a href="#1210">1210</a></td></tr
><tr id="gr_svn7768_1211"

><td id="1211"><a href="#1211">1211</a></td></tr
><tr id="gr_svn7768_1212"

><td id="1212"><a href="#1212">1212</a></td></tr
><tr id="gr_svn7768_1213"

><td id="1213"><a href="#1213">1213</a></td></tr
><tr id="gr_svn7768_1214"

><td id="1214"><a href="#1214">1214</a></td></tr
><tr id="gr_svn7768_1215"

><td id="1215"><a href="#1215">1215</a></td></tr
><tr id="gr_svn7768_1216"

><td id="1216"><a href="#1216">1216</a></td></tr
><tr id="gr_svn7768_1217"

><td id="1217"><a href="#1217">1217</a></td></tr
><tr id="gr_svn7768_1218"

><td id="1218"><a href="#1218">1218</a></td></tr
><tr id="gr_svn7768_1219"

><td id="1219"><a href="#1219">1219</a></td></tr
><tr id="gr_svn7768_1220"

><td id="1220"><a href="#1220">1220</a></td></tr
><tr id="gr_svn7768_1221"

><td id="1221"><a href="#1221">1221</a></td></tr
><tr id="gr_svn7768_1222"

><td id="1222"><a href="#1222">1222</a></td></tr
><tr id="gr_svn7768_1223"

><td id="1223"><a href="#1223">1223</a></td></tr
><tr id="gr_svn7768_1224"

><td id="1224"><a href="#1224">1224</a></td></tr
><tr id="gr_svn7768_1225"

><td id="1225"><a href="#1225">1225</a></td></tr
><tr id="gr_svn7768_1226"

><td id="1226"><a href="#1226">1226</a></td></tr
><tr id="gr_svn7768_1227"

><td id="1227"><a href="#1227">1227</a></td></tr
><tr id="gr_svn7768_1228"

><td id="1228"><a href="#1228">1228</a></td></tr
><tr id="gr_svn7768_1229"

><td id="1229"><a href="#1229">1229</a></td></tr
><tr id="gr_svn7768_1230"

><td id="1230"><a href="#1230">1230</a></td></tr
><tr id="gr_svn7768_1231"

><td id="1231"><a href="#1231">1231</a></td></tr
><tr id="gr_svn7768_1232"

><td id="1232"><a href="#1232">1232</a></td></tr
><tr id="gr_svn7768_1233"

><td id="1233"><a href="#1233">1233</a></td></tr
><tr id="gr_svn7768_1234"

><td id="1234"><a href="#1234">1234</a></td></tr
><tr id="gr_svn7768_1235"

><td id="1235"><a href="#1235">1235</a></td></tr
><tr id="gr_svn7768_1236"

><td id="1236"><a href="#1236">1236</a></td></tr
><tr id="gr_svn7768_1237"

><td id="1237"><a href="#1237">1237</a></td></tr
><tr id="gr_svn7768_1238"

><td id="1238"><a href="#1238">1238</a></td></tr
><tr id="gr_svn7768_1239"

><td id="1239"><a href="#1239">1239</a></td></tr
><tr id="gr_svn7768_1240"

><td id="1240"><a href="#1240">1240</a></td></tr
><tr id="gr_svn7768_1241"

><td id="1241"><a href="#1241">1241</a></td></tr
><tr id="gr_svn7768_1242"

><td id="1242"><a href="#1242">1242</a></td></tr
><tr id="gr_svn7768_1243"

><td id="1243"><a href="#1243">1243</a></td></tr
><tr id="gr_svn7768_1244"

><td id="1244"><a href="#1244">1244</a></td></tr
><tr id="gr_svn7768_1245"

><td id="1245"><a href="#1245">1245</a></td></tr
><tr id="gr_svn7768_1246"

><td id="1246"><a href="#1246">1246</a></td></tr
><tr id="gr_svn7768_1247"

><td id="1247"><a href="#1247">1247</a></td></tr
><tr id="gr_svn7768_1248"

><td id="1248"><a href="#1248">1248</a></td></tr
><tr id="gr_svn7768_1249"

><td id="1249"><a href="#1249">1249</a></td></tr
><tr id="gr_svn7768_1250"

><td id="1250"><a href="#1250">1250</a></td></tr
><tr id="gr_svn7768_1251"

><td id="1251"><a href="#1251">1251</a></td></tr
><tr id="gr_svn7768_1252"

><td id="1252"><a href="#1252">1252</a></td></tr
><tr id="gr_svn7768_1253"

><td id="1253"><a href="#1253">1253</a></td></tr
><tr id="gr_svn7768_1254"

><td id="1254"><a href="#1254">1254</a></td></tr
><tr id="gr_svn7768_1255"

><td id="1255"><a href="#1255">1255</a></td></tr
><tr id="gr_svn7768_1256"

><td id="1256"><a href="#1256">1256</a></td></tr
><tr id="gr_svn7768_1257"

><td id="1257"><a href="#1257">1257</a></td></tr
><tr id="gr_svn7768_1258"

><td id="1258"><a href="#1258">1258</a></td></tr
><tr id="gr_svn7768_1259"

><td id="1259"><a href="#1259">1259</a></td></tr
><tr id="gr_svn7768_1260"

><td id="1260"><a href="#1260">1260</a></td></tr
><tr id="gr_svn7768_1261"

><td id="1261"><a href="#1261">1261</a></td></tr
><tr id="gr_svn7768_1262"

><td id="1262"><a href="#1262">1262</a></td></tr
><tr id="gr_svn7768_1263"

><td id="1263"><a href="#1263">1263</a></td></tr
><tr id="gr_svn7768_1264"

><td id="1264"><a href="#1264">1264</a></td></tr
><tr id="gr_svn7768_1265"

><td id="1265"><a href="#1265">1265</a></td></tr
><tr id="gr_svn7768_1266"

><td id="1266"><a href="#1266">1266</a></td></tr
><tr id="gr_svn7768_1267"

><td id="1267"><a href="#1267">1267</a></td></tr
><tr id="gr_svn7768_1268"

><td id="1268"><a href="#1268">1268</a></td></tr
><tr id="gr_svn7768_1269"

><td id="1269"><a href="#1269">1269</a></td></tr
><tr id="gr_svn7768_1270"

><td id="1270"><a href="#1270">1270</a></td></tr
><tr id="gr_svn7768_1271"

><td id="1271"><a href="#1271">1271</a></td></tr
><tr id="gr_svn7768_1272"

><td id="1272"><a href="#1272">1272</a></td></tr
><tr id="gr_svn7768_1273"

><td id="1273"><a href="#1273">1273</a></td></tr
><tr id="gr_svn7768_1274"

><td id="1274"><a href="#1274">1274</a></td></tr
><tr id="gr_svn7768_1275"

><td id="1275"><a href="#1275">1275</a></td></tr
><tr id="gr_svn7768_1276"

><td id="1276"><a href="#1276">1276</a></td></tr
><tr id="gr_svn7768_1277"

><td id="1277"><a href="#1277">1277</a></td></tr
><tr id="gr_svn7768_1278"

><td id="1278"><a href="#1278">1278</a></td></tr
><tr id="gr_svn7768_1279"

><td id="1279"><a href="#1279">1279</a></td></tr
><tr id="gr_svn7768_1280"

><td id="1280"><a href="#1280">1280</a></td></tr
><tr id="gr_svn7768_1281"

><td id="1281"><a href="#1281">1281</a></td></tr
><tr id="gr_svn7768_1282"

><td id="1282"><a href="#1282">1282</a></td></tr
><tr id="gr_svn7768_1283"

><td id="1283"><a href="#1283">1283</a></td></tr
><tr id="gr_svn7768_1284"

><td id="1284"><a href="#1284">1284</a></td></tr
><tr id="gr_svn7768_1285"

><td id="1285"><a href="#1285">1285</a></td></tr
><tr id="gr_svn7768_1286"

><td id="1286"><a href="#1286">1286</a></td></tr
><tr id="gr_svn7768_1287"

><td id="1287"><a href="#1287">1287</a></td></tr
><tr id="gr_svn7768_1288"

><td id="1288"><a href="#1288">1288</a></td></tr
><tr id="gr_svn7768_1289"

><td id="1289"><a href="#1289">1289</a></td></tr
><tr id="gr_svn7768_1290"

><td id="1290"><a href="#1290">1290</a></td></tr
><tr id="gr_svn7768_1291"

><td id="1291"><a href="#1291">1291</a></td></tr
><tr id="gr_svn7768_1292"

><td id="1292"><a href="#1292">1292</a></td></tr
><tr id="gr_svn7768_1293"

><td id="1293"><a href="#1293">1293</a></td></tr
><tr id="gr_svn7768_1294"

><td id="1294"><a href="#1294">1294</a></td></tr
><tr id="gr_svn7768_1295"

><td id="1295"><a href="#1295">1295</a></td></tr
><tr id="gr_svn7768_1296"

><td id="1296"><a href="#1296">1296</a></td></tr
><tr id="gr_svn7768_1297"

><td id="1297"><a href="#1297">1297</a></td></tr
><tr id="gr_svn7768_1298"

><td id="1298"><a href="#1298">1298</a></td></tr
><tr id="gr_svn7768_1299"

><td id="1299"><a href="#1299">1299</a></td></tr
><tr id="gr_svn7768_1300"

><td id="1300"><a href="#1300">1300</a></td></tr
><tr id="gr_svn7768_1301"

><td id="1301"><a href="#1301">1301</a></td></tr
><tr id="gr_svn7768_1302"

><td id="1302"><a href="#1302">1302</a></td></tr
><tr id="gr_svn7768_1303"

><td id="1303"><a href="#1303">1303</a></td></tr
><tr id="gr_svn7768_1304"

><td id="1304"><a href="#1304">1304</a></td></tr
><tr id="gr_svn7768_1305"

><td id="1305"><a href="#1305">1305</a></td></tr
><tr id="gr_svn7768_1306"

><td id="1306"><a href="#1306">1306</a></td></tr
><tr id="gr_svn7768_1307"

><td id="1307"><a href="#1307">1307</a></td></tr
><tr id="gr_svn7768_1308"

><td id="1308"><a href="#1308">1308</a></td></tr
><tr id="gr_svn7768_1309"

><td id="1309"><a href="#1309">1309</a></td></tr
><tr id="gr_svn7768_1310"

><td id="1310"><a href="#1310">1310</a></td></tr
><tr id="gr_svn7768_1311"

><td id="1311"><a href="#1311">1311</a></td></tr
><tr id="gr_svn7768_1312"

><td id="1312"><a href="#1312">1312</a></td></tr
><tr id="gr_svn7768_1313"

><td id="1313"><a href="#1313">1313</a></td></tr
><tr id="gr_svn7768_1314"

><td id="1314"><a href="#1314">1314</a></td></tr
><tr id="gr_svn7768_1315"

><td id="1315"><a href="#1315">1315</a></td></tr
><tr id="gr_svn7768_1316"

><td id="1316"><a href="#1316">1316</a></td></tr
><tr id="gr_svn7768_1317"

><td id="1317"><a href="#1317">1317</a></td></tr
><tr id="gr_svn7768_1318"

><td id="1318"><a href="#1318">1318</a></td></tr
><tr id="gr_svn7768_1319"

><td id="1319"><a href="#1319">1319</a></td></tr
><tr id="gr_svn7768_1320"

><td id="1320"><a href="#1320">1320</a></td></tr
><tr id="gr_svn7768_1321"

><td id="1321"><a href="#1321">1321</a></td></tr
><tr id="gr_svn7768_1322"

><td id="1322"><a href="#1322">1322</a></td></tr
><tr id="gr_svn7768_1323"

><td id="1323"><a href="#1323">1323</a></td></tr
><tr id="gr_svn7768_1324"

><td id="1324"><a href="#1324">1324</a></td></tr
><tr id="gr_svn7768_1325"

><td id="1325"><a href="#1325">1325</a></td></tr
><tr id="gr_svn7768_1326"

><td id="1326"><a href="#1326">1326</a></td></tr
><tr id="gr_svn7768_1327"

><td id="1327"><a href="#1327">1327</a></td></tr
><tr id="gr_svn7768_1328"

><td id="1328"><a href="#1328">1328</a></td></tr
><tr id="gr_svn7768_1329"

><td id="1329"><a href="#1329">1329</a></td></tr
><tr id="gr_svn7768_1330"

><td id="1330"><a href="#1330">1330</a></td></tr
><tr id="gr_svn7768_1331"

><td id="1331"><a href="#1331">1331</a></td></tr
><tr id="gr_svn7768_1332"

><td id="1332"><a href="#1332">1332</a></td></tr
><tr id="gr_svn7768_1333"

><td id="1333"><a href="#1333">1333</a></td></tr
><tr id="gr_svn7768_1334"

><td id="1334"><a href="#1334">1334</a></td></tr
><tr id="gr_svn7768_1335"

><td id="1335"><a href="#1335">1335</a></td></tr
><tr id="gr_svn7768_1336"

><td id="1336"><a href="#1336">1336</a></td></tr
><tr id="gr_svn7768_1337"

><td id="1337"><a href="#1337">1337</a></td></tr
><tr id="gr_svn7768_1338"

><td id="1338"><a href="#1338">1338</a></td></tr
><tr id="gr_svn7768_1339"

><td id="1339"><a href="#1339">1339</a></td></tr
><tr id="gr_svn7768_1340"

><td id="1340"><a href="#1340">1340</a></td></tr
><tr id="gr_svn7768_1341"

><td id="1341"><a href="#1341">1341</a></td></tr
><tr id="gr_svn7768_1342"

><td id="1342"><a href="#1342">1342</a></td></tr
><tr id="gr_svn7768_1343"

><td id="1343"><a href="#1343">1343</a></td></tr
><tr id="gr_svn7768_1344"

><td id="1344"><a href="#1344">1344</a></td></tr
><tr id="gr_svn7768_1345"

><td id="1345"><a href="#1345">1345</a></td></tr
><tr id="gr_svn7768_1346"

><td id="1346"><a href="#1346">1346</a></td></tr
><tr id="gr_svn7768_1347"

><td id="1347"><a href="#1347">1347</a></td></tr
><tr id="gr_svn7768_1348"

><td id="1348"><a href="#1348">1348</a></td></tr
><tr id="gr_svn7768_1349"

><td id="1349"><a href="#1349">1349</a></td></tr
><tr id="gr_svn7768_1350"

><td id="1350"><a href="#1350">1350</a></td></tr
><tr id="gr_svn7768_1351"

><td id="1351"><a href="#1351">1351</a></td></tr
><tr id="gr_svn7768_1352"

><td id="1352"><a href="#1352">1352</a></td></tr
><tr id="gr_svn7768_1353"

><td id="1353"><a href="#1353">1353</a></td></tr
><tr id="gr_svn7768_1354"

><td id="1354"><a href="#1354">1354</a></td></tr
><tr id="gr_svn7768_1355"

><td id="1355"><a href="#1355">1355</a></td></tr
><tr id="gr_svn7768_1356"

><td id="1356"><a href="#1356">1356</a></td></tr
><tr id="gr_svn7768_1357"

><td id="1357"><a href="#1357">1357</a></td></tr
><tr id="gr_svn7768_1358"

><td id="1358"><a href="#1358">1358</a></td></tr
><tr id="gr_svn7768_1359"

><td id="1359"><a href="#1359">1359</a></td></tr
><tr id="gr_svn7768_1360"

><td id="1360"><a href="#1360">1360</a></td></tr
><tr id="gr_svn7768_1361"

><td id="1361"><a href="#1361">1361</a></td></tr
><tr id="gr_svn7768_1362"

><td id="1362"><a href="#1362">1362</a></td></tr
><tr id="gr_svn7768_1363"

><td id="1363"><a href="#1363">1363</a></td></tr
><tr id="gr_svn7768_1364"

><td id="1364"><a href="#1364">1364</a></td></tr
><tr id="gr_svn7768_1365"

><td id="1365"><a href="#1365">1365</a></td></tr
><tr id="gr_svn7768_1366"

><td id="1366"><a href="#1366">1366</a></td></tr
><tr id="gr_svn7768_1367"

><td id="1367"><a href="#1367">1367</a></td></tr
><tr id="gr_svn7768_1368"

><td id="1368"><a href="#1368">1368</a></td></tr
><tr id="gr_svn7768_1369"

><td id="1369"><a href="#1369">1369</a></td></tr
><tr id="gr_svn7768_1370"

><td id="1370"><a href="#1370">1370</a></td></tr
><tr id="gr_svn7768_1371"

><td id="1371"><a href="#1371">1371</a></td></tr
><tr id="gr_svn7768_1372"

><td id="1372"><a href="#1372">1372</a></td></tr
><tr id="gr_svn7768_1373"

><td id="1373"><a href="#1373">1373</a></td></tr
><tr id="gr_svn7768_1374"

><td id="1374"><a href="#1374">1374</a></td></tr
><tr id="gr_svn7768_1375"

><td id="1375"><a href="#1375">1375</a></td></tr
><tr id="gr_svn7768_1376"

><td id="1376"><a href="#1376">1376</a></td></tr
><tr id="gr_svn7768_1377"

><td id="1377"><a href="#1377">1377</a></td></tr
><tr id="gr_svn7768_1378"

><td id="1378"><a href="#1378">1378</a></td></tr
><tr id="gr_svn7768_1379"

><td id="1379"><a href="#1379">1379</a></td></tr
><tr id="gr_svn7768_1380"

><td id="1380"><a href="#1380">1380</a></td></tr
><tr id="gr_svn7768_1381"

><td id="1381"><a href="#1381">1381</a></td></tr
><tr id="gr_svn7768_1382"

><td id="1382"><a href="#1382">1382</a></td></tr
><tr id="gr_svn7768_1383"

><td id="1383"><a href="#1383">1383</a></td></tr
><tr id="gr_svn7768_1384"

><td id="1384"><a href="#1384">1384</a></td></tr
><tr id="gr_svn7768_1385"

><td id="1385"><a href="#1385">1385</a></td></tr
><tr id="gr_svn7768_1386"

><td id="1386"><a href="#1386">1386</a></td></tr
><tr id="gr_svn7768_1387"

><td id="1387"><a href="#1387">1387</a></td></tr
><tr id="gr_svn7768_1388"

><td id="1388"><a href="#1388">1388</a></td></tr
><tr id="gr_svn7768_1389"

><td id="1389"><a href="#1389">1389</a></td></tr
><tr id="gr_svn7768_1390"

><td id="1390"><a href="#1390">1390</a></td></tr
><tr id="gr_svn7768_1391"

><td id="1391"><a href="#1391">1391</a></td></tr
><tr id="gr_svn7768_1392"

><td id="1392"><a href="#1392">1392</a></td></tr
><tr id="gr_svn7768_1393"

><td id="1393"><a href="#1393">1393</a></td></tr
><tr id="gr_svn7768_1394"

><td id="1394"><a href="#1394">1394</a></td></tr
><tr id="gr_svn7768_1395"

><td id="1395"><a href="#1395">1395</a></td></tr
><tr id="gr_svn7768_1396"

><td id="1396"><a href="#1396">1396</a></td></tr
><tr id="gr_svn7768_1397"

><td id="1397"><a href="#1397">1397</a></td></tr
><tr id="gr_svn7768_1398"

><td id="1398"><a href="#1398">1398</a></td></tr
><tr id="gr_svn7768_1399"

><td id="1399"><a href="#1399">1399</a></td></tr
><tr id="gr_svn7768_1400"

><td id="1400"><a href="#1400">1400</a></td></tr
><tr id="gr_svn7768_1401"

><td id="1401"><a href="#1401">1401</a></td></tr
><tr id="gr_svn7768_1402"

><td id="1402"><a href="#1402">1402</a></td></tr
><tr id="gr_svn7768_1403"

><td id="1403"><a href="#1403">1403</a></td></tr
><tr id="gr_svn7768_1404"

><td id="1404"><a href="#1404">1404</a></td></tr
><tr id="gr_svn7768_1405"

><td id="1405"><a href="#1405">1405</a></td></tr
><tr id="gr_svn7768_1406"

><td id="1406"><a href="#1406">1406</a></td></tr
><tr id="gr_svn7768_1407"

><td id="1407"><a href="#1407">1407</a></td></tr
><tr id="gr_svn7768_1408"

><td id="1408"><a href="#1408">1408</a></td></tr
><tr id="gr_svn7768_1409"

><td id="1409"><a href="#1409">1409</a></td></tr
><tr id="gr_svn7768_1410"

><td id="1410"><a href="#1410">1410</a></td></tr
><tr id="gr_svn7768_1411"

><td id="1411"><a href="#1411">1411</a></td></tr
><tr id="gr_svn7768_1412"

><td id="1412"><a href="#1412">1412</a></td></tr
><tr id="gr_svn7768_1413"

><td id="1413"><a href="#1413">1413</a></td></tr
><tr id="gr_svn7768_1414"

><td id="1414"><a href="#1414">1414</a></td></tr
><tr id="gr_svn7768_1415"

><td id="1415"><a href="#1415">1415</a></td></tr
><tr id="gr_svn7768_1416"

><td id="1416"><a href="#1416">1416</a></td></tr
><tr id="gr_svn7768_1417"

><td id="1417"><a href="#1417">1417</a></td></tr
><tr id="gr_svn7768_1418"

><td id="1418"><a href="#1418">1418</a></td></tr
><tr id="gr_svn7768_1419"

><td id="1419"><a href="#1419">1419</a></td></tr
><tr id="gr_svn7768_1420"

><td id="1420"><a href="#1420">1420</a></td></tr
><tr id="gr_svn7768_1421"

><td id="1421"><a href="#1421">1421</a></td></tr
><tr id="gr_svn7768_1422"

><td id="1422"><a href="#1422">1422</a></td></tr
><tr id="gr_svn7768_1423"

><td id="1423"><a href="#1423">1423</a></td></tr
><tr id="gr_svn7768_1424"

><td id="1424"><a href="#1424">1424</a></td></tr
><tr id="gr_svn7768_1425"

><td id="1425"><a href="#1425">1425</a></td></tr
><tr id="gr_svn7768_1426"

><td id="1426"><a href="#1426">1426</a></td></tr
><tr id="gr_svn7768_1427"

><td id="1427"><a href="#1427">1427</a></td></tr
><tr id="gr_svn7768_1428"

><td id="1428"><a href="#1428">1428</a></td></tr
><tr id="gr_svn7768_1429"

><td id="1429"><a href="#1429">1429</a></td></tr
><tr id="gr_svn7768_1430"

><td id="1430"><a href="#1430">1430</a></td></tr
><tr id="gr_svn7768_1431"

><td id="1431"><a href="#1431">1431</a></td></tr
><tr id="gr_svn7768_1432"

><td id="1432"><a href="#1432">1432</a></td></tr
><tr id="gr_svn7768_1433"

><td id="1433"><a href="#1433">1433</a></td></tr
><tr id="gr_svn7768_1434"

><td id="1434"><a href="#1434">1434</a></td></tr
><tr id="gr_svn7768_1435"

><td id="1435"><a href="#1435">1435</a></td></tr
><tr id="gr_svn7768_1436"

><td id="1436"><a href="#1436">1436</a></td></tr
><tr id="gr_svn7768_1437"

><td id="1437"><a href="#1437">1437</a></td></tr
><tr id="gr_svn7768_1438"

><td id="1438"><a href="#1438">1438</a></td></tr
><tr id="gr_svn7768_1439"

><td id="1439"><a href="#1439">1439</a></td></tr
><tr id="gr_svn7768_1440"

><td id="1440"><a href="#1440">1440</a></td></tr
><tr id="gr_svn7768_1441"

><td id="1441"><a href="#1441">1441</a></td></tr
><tr id="gr_svn7768_1442"

><td id="1442"><a href="#1442">1442</a></td></tr
><tr id="gr_svn7768_1443"

><td id="1443"><a href="#1443">1443</a></td></tr
><tr id="gr_svn7768_1444"

><td id="1444"><a href="#1444">1444</a></td></tr
><tr id="gr_svn7768_1445"

><td id="1445"><a href="#1445">1445</a></td></tr
><tr id="gr_svn7768_1446"

><td id="1446"><a href="#1446">1446</a></td></tr
><tr id="gr_svn7768_1447"

><td id="1447"><a href="#1447">1447</a></td></tr
><tr id="gr_svn7768_1448"

><td id="1448"><a href="#1448">1448</a></td></tr
><tr id="gr_svn7768_1449"

><td id="1449"><a href="#1449">1449</a></td></tr
><tr id="gr_svn7768_1450"

><td id="1450"><a href="#1450">1450</a></td></tr
><tr id="gr_svn7768_1451"

><td id="1451"><a href="#1451">1451</a></td></tr
><tr id="gr_svn7768_1452"

><td id="1452"><a href="#1452">1452</a></td></tr
><tr id="gr_svn7768_1453"

><td id="1453"><a href="#1453">1453</a></td></tr
><tr id="gr_svn7768_1454"

><td id="1454"><a href="#1454">1454</a></td></tr
><tr id="gr_svn7768_1455"

><td id="1455"><a href="#1455">1455</a></td></tr
><tr id="gr_svn7768_1456"

><td id="1456"><a href="#1456">1456</a></td></tr
><tr id="gr_svn7768_1457"

><td id="1457"><a href="#1457">1457</a></td></tr
><tr id="gr_svn7768_1458"

><td id="1458"><a href="#1458">1458</a></td></tr
><tr id="gr_svn7768_1459"

><td id="1459"><a href="#1459">1459</a></td></tr
><tr id="gr_svn7768_1460"

><td id="1460"><a href="#1460">1460</a></td></tr
><tr id="gr_svn7768_1461"

><td id="1461"><a href="#1461">1461</a></td></tr
><tr id="gr_svn7768_1462"

><td id="1462"><a href="#1462">1462</a></td></tr
><tr id="gr_svn7768_1463"

><td id="1463"><a href="#1463">1463</a></td></tr
><tr id="gr_svn7768_1464"

><td id="1464"><a href="#1464">1464</a></td></tr
><tr id="gr_svn7768_1465"

><td id="1465"><a href="#1465">1465</a></td></tr
><tr id="gr_svn7768_1466"

><td id="1466"><a href="#1466">1466</a></td></tr
><tr id="gr_svn7768_1467"

><td id="1467"><a href="#1467">1467</a></td></tr
><tr id="gr_svn7768_1468"

><td id="1468"><a href="#1468">1468</a></td></tr
><tr id="gr_svn7768_1469"

><td id="1469"><a href="#1469">1469</a></td></tr
><tr id="gr_svn7768_1470"

><td id="1470"><a href="#1470">1470</a></td></tr
><tr id="gr_svn7768_1471"

><td id="1471"><a href="#1471">1471</a></td></tr
><tr id="gr_svn7768_1472"

><td id="1472"><a href="#1472">1472</a></td></tr
><tr id="gr_svn7768_1473"

><td id="1473"><a href="#1473">1473</a></td></tr
><tr id="gr_svn7768_1474"

><td id="1474"><a href="#1474">1474</a></td></tr
><tr id="gr_svn7768_1475"

><td id="1475"><a href="#1475">1475</a></td></tr
><tr id="gr_svn7768_1476"

><td id="1476"><a href="#1476">1476</a></td></tr
><tr id="gr_svn7768_1477"

><td id="1477"><a href="#1477">1477</a></td></tr
><tr id="gr_svn7768_1478"

><td id="1478"><a href="#1478">1478</a></td></tr
><tr id="gr_svn7768_1479"

><td id="1479"><a href="#1479">1479</a></td></tr
><tr id="gr_svn7768_1480"

><td id="1480"><a href="#1480">1480</a></td></tr
><tr id="gr_svn7768_1481"

><td id="1481"><a href="#1481">1481</a></td></tr
><tr id="gr_svn7768_1482"

><td id="1482"><a href="#1482">1482</a></td></tr
><tr id="gr_svn7768_1483"

><td id="1483"><a href="#1483">1483</a></td></tr
><tr id="gr_svn7768_1484"

><td id="1484"><a href="#1484">1484</a></td></tr
><tr id="gr_svn7768_1485"

><td id="1485"><a href="#1485">1485</a></td></tr
><tr id="gr_svn7768_1486"

><td id="1486"><a href="#1486">1486</a></td></tr
><tr id="gr_svn7768_1487"

><td id="1487"><a href="#1487">1487</a></td></tr
><tr id="gr_svn7768_1488"

><td id="1488"><a href="#1488">1488</a></td></tr
><tr id="gr_svn7768_1489"

><td id="1489"><a href="#1489">1489</a></td></tr
><tr id="gr_svn7768_1490"

><td id="1490"><a href="#1490">1490</a></td></tr
><tr id="gr_svn7768_1491"

><td id="1491"><a href="#1491">1491</a></td></tr
><tr id="gr_svn7768_1492"

><td id="1492"><a href="#1492">1492</a></td></tr
><tr id="gr_svn7768_1493"

><td id="1493"><a href="#1493">1493</a></td></tr
><tr id="gr_svn7768_1494"

><td id="1494"><a href="#1494">1494</a></td></tr
><tr id="gr_svn7768_1495"

><td id="1495"><a href="#1495">1495</a></td></tr
><tr id="gr_svn7768_1496"

><td id="1496"><a href="#1496">1496</a></td></tr
><tr id="gr_svn7768_1497"

><td id="1497"><a href="#1497">1497</a></td></tr
><tr id="gr_svn7768_1498"

><td id="1498"><a href="#1498">1498</a></td></tr
><tr id="gr_svn7768_1499"

><td id="1499"><a href="#1499">1499</a></td></tr
><tr id="gr_svn7768_1500"

><td id="1500"><a href="#1500">1500</a></td></tr
><tr id="gr_svn7768_1501"

><td id="1501"><a href="#1501">1501</a></td></tr
><tr id="gr_svn7768_1502"

><td id="1502"><a href="#1502">1502</a></td></tr
><tr id="gr_svn7768_1503"

><td id="1503"><a href="#1503">1503</a></td></tr
><tr id="gr_svn7768_1504"

><td id="1504"><a href="#1504">1504</a></td></tr
><tr id="gr_svn7768_1505"

><td id="1505"><a href="#1505">1505</a></td></tr
><tr id="gr_svn7768_1506"

><td id="1506"><a href="#1506">1506</a></td></tr
><tr id="gr_svn7768_1507"

><td id="1507"><a href="#1507">1507</a></td></tr
><tr id="gr_svn7768_1508"

><td id="1508"><a href="#1508">1508</a></td></tr
><tr id="gr_svn7768_1509"

><td id="1509"><a href="#1509">1509</a></td></tr
><tr id="gr_svn7768_1510"

><td id="1510"><a href="#1510">1510</a></td></tr
><tr id="gr_svn7768_1511"

><td id="1511"><a href="#1511">1511</a></td></tr
><tr id="gr_svn7768_1512"

><td id="1512"><a href="#1512">1512</a></td></tr
><tr id="gr_svn7768_1513"

><td id="1513"><a href="#1513">1513</a></td></tr
><tr id="gr_svn7768_1514"

><td id="1514"><a href="#1514">1514</a></td></tr
><tr id="gr_svn7768_1515"

><td id="1515"><a href="#1515">1515</a></td></tr
><tr id="gr_svn7768_1516"

><td id="1516"><a href="#1516">1516</a></td></tr
><tr id="gr_svn7768_1517"

><td id="1517"><a href="#1517">1517</a></td></tr
><tr id="gr_svn7768_1518"

><td id="1518"><a href="#1518">1518</a></td></tr
><tr id="gr_svn7768_1519"

><td id="1519"><a href="#1519">1519</a></td></tr
><tr id="gr_svn7768_1520"

><td id="1520"><a href="#1520">1520</a></td></tr
><tr id="gr_svn7768_1521"

><td id="1521"><a href="#1521">1521</a></td></tr
><tr id="gr_svn7768_1522"

><td id="1522"><a href="#1522">1522</a></td></tr
><tr id="gr_svn7768_1523"

><td id="1523"><a href="#1523">1523</a></td></tr
><tr id="gr_svn7768_1524"

><td id="1524"><a href="#1524">1524</a></td></tr
><tr id="gr_svn7768_1525"

><td id="1525"><a href="#1525">1525</a></td></tr
><tr id="gr_svn7768_1526"

><td id="1526"><a href="#1526">1526</a></td></tr
><tr id="gr_svn7768_1527"

><td id="1527"><a href="#1527">1527</a></td></tr
><tr id="gr_svn7768_1528"

><td id="1528"><a href="#1528">1528</a></td></tr
><tr id="gr_svn7768_1529"

><td id="1529"><a href="#1529">1529</a></td></tr
><tr id="gr_svn7768_1530"

><td id="1530"><a href="#1530">1530</a></td></tr
><tr id="gr_svn7768_1531"

><td id="1531"><a href="#1531">1531</a></td></tr
><tr id="gr_svn7768_1532"

><td id="1532"><a href="#1532">1532</a></td></tr
><tr id="gr_svn7768_1533"

><td id="1533"><a href="#1533">1533</a></td></tr
><tr id="gr_svn7768_1534"

><td id="1534"><a href="#1534">1534</a></td></tr
><tr id="gr_svn7768_1535"

><td id="1535"><a href="#1535">1535</a></td></tr
><tr id="gr_svn7768_1536"

><td id="1536"><a href="#1536">1536</a></td></tr
><tr id="gr_svn7768_1537"

><td id="1537"><a href="#1537">1537</a></td></tr
><tr id="gr_svn7768_1538"

><td id="1538"><a href="#1538">1538</a></td></tr
><tr id="gr_svn7768_1539"

><td id="1539"><a href="#1539">1539</a></td></tr
><tr id="gr_svn7768_1540"

><td id="1540"><a href="#1540">1540</a></td></tr
><tr id="gr_svn7768_1541"

><td id="1541"><a href="#1541">1541</a></td></tr
><tr id="gr_svn7768_1542"

><td id="1542"><a href="#1542">1542</a></td></tr
><tr id="gr_svn7768_1543"

><td id="1543"><a href="#1543">1543</a></td></tr
><tr id="gr_svn7768_1544"

><td id="1544"><a href="#1544">1544</a></td></tr
><tr id="gr_svn7768_1545"

><td id="1545"><a href="#1545">1545</a></td></tr
><tr id="gr_svn7768_1546"

><td id="1546"><a href="#1546">1546</a></td></tr
><tr id="gr_svn7768_1547"

><td id="1547"><a href="#1547">1547</a></td></tr
><tr id="gr_svn7768_1548"

><td id="1548"><a href="#1548">1548</a></td></tr
><tr id="gr_svn7768_1549"

><td id="1549"><a href="#1549">1549</a></td></tr
><tr id="gr_svn7768_1550"

><td id="1550"><a href="#1550">1550</a></td></tr
><tr id="gr_svn7768_1551"

><td id="1551"><a href="#1551">1551</a></td></tr
><tr id="gr_svn7768_1552"

><td id="1552"><a href="#1552">1552</a></td></tr
><tr id="gr_svn7768_1553"

><td id="1553"><a href="#1553">1553</a></td></tr
><tr id="gr_svn7768_1554"

><td id="1554"><a href="#1554">1554</a></td></tr
><tr id="gr_svn7768_1555"

><td id="1555"><a href="#1555">1555</a></td></tr
><tr id="gr_svn7768_1556"

><td id="1556"><a href="#1556">1556</a></td></tr
><tr id="gr_svn7768_1557"

><td id="1557"><a href="#1557">1557</a></td></tr
><tr id="gr_svn7768_1558"

><td id="1558"><a href="#1558">1558</a></td></tr
><tr id="gr_svn7768_1559"

><td id="1559"><a href="#1559">1559</a></td></tr
><tr id="gr_svn7768_1560"

><td id="1560"><a href="#1560">1560</a></td></tr
><tr id="gr_svn7768_1561"

><td id="1561"><a href="#1561">1561</a></td></tr
><tr id="gr_svn7768_1562"

><td id="1562"><a href="#1562">1562</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre class="prettyprint"><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint lang-java"><table id="src_table_0"><tr
id=sl_svn7768_1

><td class="source">/* -*- mode: java; c-basic-offset: 2; indent-tabs-mode: nil -*- */<br></td></tr
><tr
id=sl_svn7768_2

><td class="source"><br></td></tr
><tr
id=sl_svn7768_3

><td class="source">/*<br></td></tr
><tr
id=sl_svn7768_4

><td class="source">  Part of the Processing project - http://processing.org<br></td></tr
><tr
id=sl_svn7768_5

><td class="source"><br></td></tr
><tr
id=sl_svn7768_6

><td class="source">  Copyright (c) 2006-10 Ben Fry and Casey Reas<br></td></tr
><tr
id=sl_svn7768_7

><td class="source">  Copyright (c) 2004-06 Michael Chang<br></td></tr
><tr
id=sl_svn7768_8

><td class="source"><br></td></tr
><tr
id=sl_svn7768_9

><td class="source">  This library is free software; you can redistribute it and/or<br></td></tr
><tr
id=sl_svn7768_10

><td class="source">  modify it under the terms of the GNU Lesser General Public<br></td></tr
><tr
id=sl_svn7768_11

><td class="source">  License version 2.1 as published by the Free Software Foundation.<br></td></tr
><tr
id=sl_svn7768_12

><td class="source"><br></td></tr
><tr
id=sl_svn7768_13

><td class="source">  This library is distributed in the hope that it will be useful,<br></td></tr
><tr
id=sl_svn7768_14

><td class="source">  but WITHOUT ANY WARRANTY; without even the implied warranty of<br></td></tr
><tr
id=sl_svn7768_15

><td class="source">  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU<br></td></tr
><tr
id=sl_svn7768_16

><td class="source">  Lesser General Public License for more details.<br></td></tr
><tr
id=sl_svn7768_17

><td class="source"><br></td></tr
><tr
id=sl_svn7768_18

><td class="source">  You should have received a copy of the GNU Lesser General<br></td></tr
><tr
id=sl_svn7768_19

><td class="source">  Public License along with this library; if not, write to the<br></td></tr
><tr
id=sl_svn7768_20

><td class="source">  Free Software Foundation, Inc., 59 Temple Place, Suite 330,<br></td></tr
><tr
id=sl_svn7768_21

><td class="source">  Boston, MA  02111-1307  USA<br></td></tr
><tr
id=sl_svn7768_22

><td class="source">*/<br></td></tr
><tr
id=sl_svn7768_23

><td class="source"><br></td></tr
><tr
id=sl_svn7768_24

><td class="source">package processing.core;<br></td></tr
><tr
id=sl_svn7768_25

><td class="source"><br></td></tr
><tr
id=sl_svn7768_26

><td class="source">import java.awt.Paint;<br></td></tr
><tr
id=sl_svn7768_27

><td class="source">import java.awt.PaintContext;<br></td></tr
><tr
id=sl_svn7768_28

><td class="source">import java.awt.Rectangle;<br></td></tr
><tr
id=sl_svn7768_29

><td class="source">import java.awt.RenderingHints;<br></td></tr
><tr
id=sl_svn7768_30

><td class="source">import java.awt.geom.AffineTransform;<br></td></tr
><tr
id=sl_svn7768_31

><td class="source">import java.awt.geom.Point2D;<br></td></tr
><tr
id=sl_svn7768_32

><td class="source">import java.awt.geom.Rectangle2D;<br></td></tr
><tr
id=sl_svn7768_33

><td class="source">import java.awt.image.ColorModel;<br></td></tr
><tr
id=sl_svn7768_34

><td class="source">import java.awt.image.Raster;<br></td></tr
><tr
id=sl_svn7768_35

><td class="source">import java.awt.image.WritableRaster;<br></td></tr
><tr
id=sl_svn7768_36

><td class="source">import java.util.HashMap;<br></td></tr
><tr
id=sl_svn7768_37

><td class="source"><br></td></tr
><tr
id=sl_svn7768_38

><td class="source">import processing.xml.XMLElement;<br></td></tr
><tr
id=sl_svn7768_39

><td class="source"><br></td></tr
><tr
id=sl_svn7768_40

><td class="source"><br></td></tr
><tr
id=sl_svn7768_41

><td class="source">/**<br></td></tr
><tr
id=sl_svn7768_42

><td class="source"> * SVG stands for Scalable Vector Graphics, a portable graphics format. It is<br></td></tr
><tr
id=sl_svn7768_43

><td class="source"> * a vector format so it allows for infinite resolution and relatively small<br></td></tr
><tr
id=sl_svn7768_44

><td class="source"> * file sizes. Most modern media software can view SVG files, including Adobe<br></td></tr
><tr
id=sl_svn7768_45

><td class="source"> * products, Firefox, etc. Illustrator and Inkscape can edit SVG files.<br></td></tr
><tr
id=sl_svn7768_46

><td class="source"> * &lt;p&gt;<br></td></tr
><tr
id=sl_svn7768_47

><td class="source"> * We have no intention of turning this into a full-featured SVG library.<br></td></tr
><tr
id=sl_svn7768_48

><td class="source"> * The goal of this project is a basic shape importer that is small enough<br></td></tr
><tr
id=sl_svn7768_49

><td class="source"> * to be included with applets, meaning that its download size should be<br></td></tr
><tr
id=sl_svn7768_50

><td class="source"> * in the neighborhood of 25-30k. Starting with release 0149, this library<br></td></tr
><tr
id=sl_svn7768_51

><td class="source"> * has been incorporated into the core via the loadShape() command, because<br></td></tr
><tr
id=sl_svn7768_52

><td class="source"> * vector shape data is just as important as the image data from loadImage().<br></td></tr
><tr
id=sl_svn7768_53

><td class="source"> * &lt;p&gt;<br></td></tr
><tr
id=sl_svn7768_54

><td class="source"> * For more sophisticated import/export, consider the<br></td></tr
><tr
id=sl_svn7768_55

><td class="source"> * &lt;A HREF=&quot;http://xmlgraphics.apache.org/batik/&quot;&gt;Batik&lt;/A&gt;<br></td></tr
><tr
id=sl_svn7768_56

><td class="source"> * library from the Apache Software Foundation. Future improvements to this<br></td></tr
><tr
id=sl_svn7768_57

><td class="source"> * library may focus on this properly supporting a specific subset of SVG,<br></td></tr
><tr
id=sl_svn7768_58

><td class="source"> * for instance the simpler SVG profiles known as<br></td></tr
><tr
id=sl_svn7768_59

><td class="source"> * &lt;A HREF=&quot;http://www.w3.org/TR/SVGMobile/&quot;&gt;SVG Tiny or Basic&lt;/A&gt;,<br></td></tr
><tr
id=sl_svn7768_60

><td class="source"> * although we still would not support the interactivity options.<br></td></tr
><tr
id=sl_svn7768_61

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_62

><td class="source"> * &lt;p&gt; &lt;hr noshade&gt; &lt;p&gt;<br></td></tr
><tr
id=sl_svn7768_63

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_64

><td class="source"> * A minimal example program using SVG:<br></td></tr
><tr
id=sl_svn7768_65

><td class="source"> * (assuming a working moo.svg is in your data folder)<br></td></tr
><tr
id=sl_svn7768_66

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_67

><td class="source"> * &lt;PRE&gt;<br></td></tr
><tr
id=sl_svn7768_68

><td class="source"> * PShape moo;<br></td></tr
><tr
id=sl_svn7768_69

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_70

><td class="source"> * void setup() {<br></td></tr
><tr
id=sl_svn7768_71

><td class="source"> *   size(400, 400);<br></td></tr
><tr
id=sl_svn7768_72

><td class="source"> *   moo = loadShape(&quot;moo.svg&quot;);<br></td></tr
><tr
id=sl_svn7768_73

><td class="source"> * }<br></td></tr
><tr
id=sl_svn7768_74

><td class="source"> * void draw() {<br></td></tr
><tr
id=sl_svn7768_75

><td class="source"> *   background(255);<br></td></tr
><tr
id=sl_svn7768_76

><td class="source"> *   shape(moo, mouseX, mouseY);<br></td></tr
><tr
id=sl_svn7768_77

><td class="source"> * }<br></td></tr
><tr
id=sl_svn7768_78

><td class="source"> * &lt;/PRE&gt;<br></td></tr
><tr
id=sl_svn7768_79

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_80

><td class="source"> * This code is based on the Candy library written by Michael Chang, which was<br></td></tr
><tr
id=sl_svn7768_81

><td class="source"> * later revised and expanded for use as a Processing core library by Ben Fry.<br></td></tr
><tr
id=sl_svn7768_82

><td class="source"> * Thanks to Ricard Marxer Pinon for help with better Inkscape support in 0154.<br></td></tr
><tr
id=sl_svn7768_83

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_84

><td class="source"> * &lt;p&gt; &lt;hr noshade&gt; &lt;p&gt;<br></td></tr
><tr
id=sl_svn7768_85

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_86

><td class="source"> * Late October 2008 revisions from ricardmp, incorporated by fry (0154)<br></td></tr
><tr
id=sl_svn7768_87

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_88

><td class="source"> * &lt;LI&gt;Better style attribute handling, enabling better Inkscape support.<br></td></tr
><tr
id=sl_svn7768_89

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_90

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_91

><td class="source"> * October 2008 revisions by fry (Processing 0149, pre-1.0)<br></td></tr
><tr
id=sl_svn7768_92

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_93

><td class="source"> * &lt;LI&gt; Candy is no longer a separate library, and is instead part of core.<br></td></tr
><tr
id=sl_svn7768_94

><td class="source"> * &lt;LI&gt; Loading now works through loadShape()<br></td></tr
><tr
id=sl_svn7768_95

><td class="source"> * &lt;LI&gt; Shapes are now drawn using the new PGraphics shape() method.<br></td></tr
><tr
id=sl_svn7768_96

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_97

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_98

><td class="source"> * August 2008 revisions by fry (Processing 0149)<br></td></tr
><tr
id=sl_svn7768_99

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_100

><td class="source"> * &lt;LI&gt; Major changes to rework around PShape.<br></td></tr
><tr
id=sl_svn7768_101

><td class="source"> * &lt;LI&gt; Now implementing more of the &quot;transform&quot; attribute.<br></td></tr
><tr
id=sl_svn7768_102

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_103

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_104

><td class="source"> * February 2008 revisions by fry (Processing 0136)<br></td></tr
><tr
id=sl_svn7768_105

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_106

><td class="source"> * &lt;LI&gt; Added support for quadratic curves in paths (Q, q, T, and t operators)<br></td></tr
><tr
id=sl_svn7768_107

><td class="source"> * &lt;LI&gt; Support for reading SVG font data (though not rendering it yet)<br></td></tr
><tr
id=sl_svn7768_108

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_109

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_110

><td class="source"> * Revisions for &quot;Candy 2&quot; November 2006 by fry<br></td></tr
><tr
id=sl_svn7768_111

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_112

><td class="source"> * &lt;LI&gt; Switch to the new processing.xml library<br></td></tr
><tr
id=sl_svn7768_113

><td class="source"> * &lt;LI&gt; Several bug fixes for parsing of shape data<br></td></tr
><tr
id=sl_svn7768_114

><td class="source"> * &lt;LI&gt; Support for linear and radial gradients<br></td></tr
><tr
id=sl_svn7768_115

><td class="source"> * &lt;LI&gt; Support for additional types of shapes<br></td></tr
><tr
id=sl_svn7768_116

><td class="source"> * &lt;LI&gt; Added compound shapes (shapes with interior points)<br></td></tr
><tr
id=sl_svn7768_117

><td class="source"> * &lt;LI&gt; Added methods to get shapes from an internal table<br></td></tr
><tr
id=sl_svn7768_118

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_119

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_120

><td class="source"> * Revision 10/31/06 by flux<br></td></tr
><tr
id=sl_svn7768_121

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_122

><td class="source"> * &lt;LI&gt; Now properly supports Processing 0118<br></td></tr
><tr
id=sl_svn7768_123

><td class="source"> * &lt;LI&gt; Fixed a bunch of things for Casey&#39;s students and general buggity.<br></td></tr
><tr
id=sl_svn7768_124

><td class="source"> * &lt;LI&gt; Will now properly draw #FFFFFFFF colors (were being represented as -1)<br></td></tr
><tr
id=sl_svn7768_125

><td class="source"> * &lt;LI&gt; SVGs without &lt;g&gt; tags are now properly caught and loaded<br></td></tr
><tr
id=sl_svn7768_126

><td class="source"> * &lt;LI&gt; Added a method customStyle() for overriding SVG colors/styles<br></td></tr
><tr
id=sl_svn7768_127

><td class="source"> * &lt;LI&gt; Added a method SVGStyle() to go back to using SVG colors/styles<br></td></tr
><tr
id=sl_svn7768_128

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_129

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_130

><td class="source"> * Some SVG objects and features may not yet be supported.<br></td></tr
><tr
id=sl_svn7768_131

><td class="source"> * Here is a partial list of non-included features<br></td></tr
><tr
id=sl_svn7768_132

><td class="source"> * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_133

><td class="source"> * &lt;LI&gt; Rounded rectangles<br></td></tr
><tr
id=sl_svn7768_134

><td class="source"> * &lt;LI&gt; Drop shadow objects<br></td></tr
><tr
id=sl_svn7768_135

><td class="source"> * &lt;LI&gt; Typography<br></td></tr
><tr
id=sl_svn7768_136

><td class="source"> * &lt;LI&gt; &lt;STRIKE&gt;Layers&lt;/STRIKE&gt; added for Candy 2<br></td></tr
><tr
id=sl_svn7768_137

><td class="source"> * &lt;LI&gt; Patterns<br></td></tr
><tr
id=sl_svn7768_138

><td class="source"> * &lt;LI&gt; Embedded images<br></td></tr
><tr
id=sl_svn7768_139

><td class="source"> * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_140

><td class="source"> *<br></td></tr
><tr
id=sl_svn7768_141

><td class="source"> * For those interested, the SVG specification can be found<br></td></tr
><tr
id=sl_svn7768_142

><td class="source"> * &lt;A HREF=&quot;http://www.w3.org/TR/SVG&quot;&gt;here&lt;/A&gt;.<br></td></tr
><tr
id=sl_svn7768_143

><td class="source"> */<br></td></tr
><tr
id=sl_svn7768_144

><td class="source">public class PShapeSVG extends PShape {<br></td></tr
><tr
id=sl_svn7768_145

><td class="source">  XMLElement element;<br></td></tr
><tr
id=sl_svn7768_146

><td class="source"><br></td></tr
><tr
id=sl_svn7768_147

><td class="source">  /// Values between 0 and 1.<br></td></tr
><tr
id=sl_svn7768_148

><td class="source">  float opacity;<br></td></tr
><tr
id=sl_svn7768_149

><td class="source">  float strokeOpacity;<br></td></tr
><tr
id=sl_svn7768_150

><td class="source">  float fillOpacity;<br></td></tr
><tr
id=sl_svn7768_151

><td class="source"><br></td></tr
><tr
id=sl_svn7768_152

><td class="source"><br></td></tr
><tr
id=sl_svn7768_153

><td class="source">  Gradient strokeGradient;<br></td></tr
><tr
id=sl_svn7768_154

><td class="source">  Paint strokeGradientPaint;<br></td></tr
><tr
id=sl_svn7768_155

><td class="source">  String strokeName;  // id of another object, gradients only?<br></td></tr
><tr
id=sl_svn7768_156

><td class="source"><br></td></tr
><tr
id=sl_svn7768_157

><td class="source">  Gradient fillGradient;<br></td></tr
><tr
id=sl_svn7768_158

><td class="source">  Paint fillGradientPaint;<br></td></tr
><tr
id=sl_svn7768_159

><td class="source">  String fillName;  // id of another object<br></td></tr
><tr
id=sl_svn7768_160

><td class="source"><br></td></tr
><tr
id=sl_svn7768_161

><td class="source"><br></td></tr
><tr
id=sl_svn7768_162

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_163

><td class="source">   * Initializes a new SVG Object with the given filename.<br></td></tr
><tr
id=sl_svn7768_164

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_165

><td class="source">  public PShapeSVG(PApplet parent, String filename) {<br></td></tr
><tr
id=sl_svn7768_166

><td class="source">    // this will grab the root document, starting &lt;svg ...&gt;<br></td></tr
><tr
id=sl_svn7768_167

><td class="source">    // the xml version and initial comments are ignored<br></td></tr
><tr
id=sl_svn7768_168

><td class="source">    this(new XMLElement(parent, filename));<br></td></tr
><tr
id=sl_svn7768_169

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_170

><td class="source"><br></td></tr
><tr
id=sl_svn7768_171

><td class="source"><br></td></tr
><tr
id=sl_svn7768_172

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_173

><td class="source">   * Initializes a new SVG Object from the given XMLElement.<br></td></tr
><tr
id=sl_svn7768_174

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_175

><td class="source">  public PShapeSVG(XMLElement svg) {<br></td></tr
><tr
id=sl_svn7768_176

><td class="source">    this(null, svg);<br></td></tr
><tr
id=sl_svn7768_177

><td class="source"><br></td></tr
><tr
id=sl_svn7768_178

><td class="source">    if (!svg.getName().equals(&quot;svg&quot;)) {<br></td></tr
><tr
id=sl_svn7768_179

><td class="source">      throw new RuntimeException(&quot;root is not &lt;svg&gt;, it&#39;s &lt;&quot; + svg.getName() + &quot;&gt;&quot;);<br></td></tr
><tr
id=sl_svn7768_180

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_181

><td class="source"><br></td></tr
><tr
id=sl_svn7768_182

><td class="source">    // not proper parsing of the viewBox, but will cover us for cases where<br></td></tr
><tr
id=sl_svn7768_183

><td class="source">    // the width and height of the object is not specified<br></td></tr
><tr
id=sl_svn7768_184

><td class="source">    String viewBoxStr = svg.getString(&quot;viewBox&quot;);<br></td></tr
><tr
id=sl_svn7768_185

><td class="source">    if (viewBoxStr != null) {<br></td></tr
><tr
id=sl_svn7768_186

><td class="source">      int[] viewBox = PApplet.parseInt(PApplet.splitTokens(viewBoxStr));<br></td></tr
><tr
id=sl_svn7768_187

><td class="source">      width = viewBox[2];<br></td></tr
><tr
id=sl_svn7768_188

><td class="source">      height = viewBox[3];<br></td></tr
><tr
id=sl_svn7768_189

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_190

><td class="source"><br></td></tr
><tr
id=sl_svn7768_191

><td class="source">    // TODO if viewbox is not same as width/height, then use it to scale<br></td></tr
><tr
id=sl_svn7768_192

><td class="source">    // the original objects. for now, viewbox only used when width/height<br></td></tr
><tr
id=sl_svn7768_193

><td class="source">    // are empty values (which by the spec means w/h of &quot;100%&quot;<br></td></tr
><tr
id=sl_svn7768_194

><td class="source">    String unitWidth = svg.getString(&quot;width&quot;);<br></td></tr
><tr
id=sl_svn7768_195

><td class="source">    String unitHeight = svg.getString(&quot;height&quot;);<br></td></tr
><tr
id=sl_svn7768_196

><td class="source">    if (unitWidth != null) {<br></td></tr
><tr
id=sl_svn7768_197

><td class="source">      width = parseUnitSize(unitWidth);<br></td></tr
><tr
id=sl_svn7768_198

><td class="source">      height = parseUnitSize(unitHeight);<br></td></tr
><tr
id=sl_svn7768_199

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn7768_200

><td class="source">      if ((width == 0) || (height == 0)) {<br></td></tr
><tr
id=sl_svn7768_201

><td class="source">        //throw new RuntimeException(&quot;width/height not specified&quot;);<br></td></tr
><tr
id=sl_svn7768_202

><td class="source">        PGraphics.showWarning(&quot;The width and/or height is not &quot; +<br></td></tr
><tr
id=sl_svn7768_203

><td class="source">                              &quot;readable in the &lt;svg&gt; tag of this file.&quot;);<br></td></tr
><tr
id=sl_svn7768_204

><td class="source">        // For the spec, the default is 100% and 100%. For purposes<br></td></tr
><tr
id=sl_svn7768_205

><td class="source">        // here, insert a dummy value because this is prolly just a<br></td></tr
><tr
id=sl_svn7768_206

><td class="source">        // font or something for which the w/h doesn&#39;t matter.<br></td></tr
><tr
id=sl_svn7768_207

><td class="source">        width = 1;<br></td></tr
><tr
id=sl_svn7768_208

><td class="source">        height = 1;<br></td></tr
><tr
id=sl_svn7768_209

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_210

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_211

><td class="source"><br></td></tr
><tr
id=sl_svn7768_212

><td class="source">    //root = new Group(null, svg);<br></td></tr
><tr
id=sl_svn7768_213

><td class="source">    parseChildren(svg);  // ?<br></td></tr
><tr
id=sl_svn7768_214

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_215

><td class="source"><br></td></tr
><tr
id=sl_svn7768_216

><td class="source"><br></td></tr
><tr
id=sl_svn7768_217

><td class="source">  public PShapeSVG(PShapeSVG parent, XMLElement properties) {<br></td></tr
><tr
id=sl_svn7768_218

><td class="source">    // Need to set this so that findChild() works. <br></td></tr
><tr
id=sl_svn7768_219

><td class="source">    // Otherwise &#39;parent&#39; is null until addChild() is called later.<br></td></tr
><tr
id=sl_svn7768_220

><td class="source">    this.parent = parent;<br></td></tr
><tr
id=sl_svn7768_221

><td class="source"><br></td></tr
><tr
id=sl_svn7768_222

><td class="source">    if (parent == null) {<br></td></tr
><tr
id=sl_svn7768_223

><td class="source">      // set values to their defaults according to the SVG spec<br></td></tr
><tr
id=sl_svn7768_224

><td class="source">      stroke = false;<br></td></tr
><tr
id=sl_svn7768_225

><td class="source">      strokeColor = 0xff000000;<br></td></tr
><tr
id=sl_svn7768_226

><td class="source">      strokeWeight = 1;<br></td></tr
><tr
id=sl_svn7768_227

><td class="source">      strokeCap = PConstants.SQUARE;  // equivalent to BUTT in svg spec<br></td></tr
><tr
id=sl_svn7768_228

><td class="source">      strokeJoin = PConstants.MITER;<br></td></tr
><tr
id=sl_svn7768_229

><td class="source">      strokeGradient = null;<br></td></tr
><tr
id=sl_svn7768_230

><td class="source">      strokeGradientPaint = null;<br></td></tr
><tr
id=sl_svn7768_231

><td class="source">      strokeName = null;<br></td></tr
><tr
id=sl_svn7768_232

><td class="source"><br></td></tr
><tr
id=sl_svn7768_233

><td class="source">      fill = true;<br></td></tr
><tr
id=sl_svn7768_234

><td class="source">      fillColor = 0xff000000;<br></td></tr
><tr
id=sl_svn7768_235

><td class="source">      fillGradient = null;<br></td></tr
><tr
id=sl_svn7768_236

><td class="source">      fillGradientPaint = null;<br></td></tr
><tr
id=sl_svn7768_237

><td class="source">      fillName = null;<br></td></tr
><tr
id=sl_svn7768_238

><td class="source"><br></td></tr
><tr
id=sl_svn7768_239

><td class="source">      //hasTransform = false;<br></td></tr
><tr
id=sl_svn7768_240

><td class="source">      //transformation = null; //new float[] { 1, 0, 0, 1, 0, 0 };<br></td></tr
><tr
id=sl_svn7768_241

><td class="source"><br></td></tr
><tr
id=sl_svn7768_242

><td class="source">      strokeOpacity = 1;<br></td></tr
><tr
id=sl_svn7768_243

><td class="source">      fillOpacity = 1;<br></td></tr
><tr
id=sl_svn7768_244

><td class="source">      opacity = 1;<br></td></tr
><tr
id=sl_svn7768_245

><td class="source"><br></td></tr
><tr
id=sl_svn7768_246

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn7768_247

><td class="source">      stroke = parent.stroke;<br></td></tr
><tr
id=sl_svn7768_248

><td class="source">      strokeColor = parent.strokeColor;<br></td></tr
><tr
id=sl_svn7768_249

><td class="source">      strokeWeight = parent.strokeWeight;<br></td></tr
><tr
id=sl_svn7768_250

><td class="source">      strokeCap = parent.strokeCap;<br></td></tr
><tr
id=sl_svn7768_251

><td class="source">      strokeJoin = parent.strokeJoin;<br></td></tr
><tr
id=sl_svn7768_252

><td class="source">      strokeGradient = parent.strokeGradient;<br></td></tr
><tr
id=sl_svn7768_253

><td class="source">      strokeGradientPaint = parent.strokeGradientPaint;<br></td></tr
><tr
id=sl_svn7768_254

><td class="source">      strokeName = parent.strokeName;<br></td></tr
><tr
id=sl_svn7768_255

><td class="source"><br></td></tr
><tr
id=sl_svn7768_256

><td class="source">      fill = parent.fill;<br></td></tr
><tr
id=sl_svn7768_257

><td class="source">      fillColor = parent.fillColor;<br></td></tr
><tr
id=sl_svn7768_258

><td class="source">      fillGradient = parent.fillGradient;<br></td></tr
><tr
id=sl_svn7768_259

><td class="source">      fillGradientPaint = parent.fillGradientPaint;<br></td></tr
><tr
id=sl_svn7768_260

><td class="source">      fillName = parent.fillName;<br></td></tr
><tr
id=sl_svn7768_261

><td class="source"><br></td></tr
><tr
id=sl_svn7768_262

><td class="source">      //hasTransform = parent.hasTransform;<br></td></tr
><tr
id=sl_svn7768_263

><td class="source">      //transformation = parent.transformation;<br></td></tr
><tr
id=sl_svn7768_264

><td class="source"><br></td></tr
><tr
id=sl_svn7768_265

><td class="source">      opacity = parent.opacity;<br></td></tr
><tr
id=sl_svn7768_266

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_267

><td class="source"><br></td></tr
><tr
id=sl_svn7768_268

><td class="source">    element = properties;<br></td></tr
><tr
id=sl_svn7768_269

><td class="source">    name = properties.getString(&quot;id&quot;);<br></td></tr
><tr
id=sl_svn7768_270

><td class="source">    // @#$(* adobe illustrator mangles names of objects when re-saving<br></td></tr
><tr
id=sl_svn7768_271

><td class="source">    if (name != null) {<br></td></tr
><tr
id=sl_svn7768_272

><td class="source">      while (true) {<br></td></tr
><tr
id=sl_svn7768_273

><td class="source">        String[] m = PApplet.match(name, &quot;_x([A-Za-z0-9]{2})_&quot;);<br></td></tr
><tr
id=sl_svn7768_274

><td class="source">        if (m == null) break;<br></td></tr
><tr
id=sl_svn7768_275

><td class="source">        char repair = (char) PApplet.unhex(m[1]);<br></td></tr
><tr
id=sl_svn7768_276

><td class="source">        name = name.replace(m[0], &quot;&quot; + repair);<br></td></tr
><tr
id=sl_svn7768_277

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_278

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_279

><td class="source"><br></td></tr
><tr
id=sl_svn7768_280

><td class="source">    String displayStr = properties.getString(&quot;display&quot;, &quot;inline&quot;);<br></td></tr
><tr
id=sl_svn7768_281

><td class="source">    visible = !displayStr.equals(&quot;none&quot;);<br></td></tr
><tr
id=sl_svn7768_282

><td class="source"><br></td></tr
><tr
id=sl_svn7768_283

><td class="source">    String transformStr = properties.getString(&quot;transform&quot;);<br></td></tr
><tr
id=sl_svn7768_284

><td class="source">    if (transformStr != null) {<br></td></tr
><tr
id=sl_svn7768_285

><td class="source">      matrix = parseMatrix(transformStr);<br></td></tr
><tr
id=sl_svn7768_286

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_287

><td class="source"><br></td></tr
><tr
id=sl_svn7768_288

><td class="source">    parseColors(properties);<br></td></tr
><tr
id=sl_svn7768_289

><td class="source">    parseChildren(properties);<br></td></tr
><tr
id=sl_svn7768_290

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_291

><td class="source"><br></td></tr
><tr
id=sl_svn7768_292

><td class="source"><br></td></tr
><tr
id=sl_svn7768_293

><td class="source">  protected void parseChildren(XMLElement graphics) {<br></td></tr
><tr
id=sl_svn7768_294

><td class="source">    XMLElement[] elements = graphics.getChildren();<br></td></tr
><tr
id=sl_svn7768_295

><td class="source">    children = new PShape[elements.length];<br></td></tr
><tr
id=sl_svn7768_296

><td class="source">    childCount = 0;<br></td></tr
><tr
id=sl_svn7768_297

><td class="source"><br></td></tr
><tr
id=sl_svn7768_298

><td class="source">    for (XMLElement elem : elements) {<br></td></tr
><tr
id=sl_svn7768_299

><td class="source">      PShape kid = parseChild(elem);<br></td></tr
><tr
id=sl_svn7768_300

><td class="source">      if (kid != null) {<br></td></tr
><tr
id=sl_svn7768_301

><td class="source">//        if (kid.name != null) {<br></td></tr
><tr
id=sl_svn7768_302

><td class="source">//          System.out.println(&quot;adding child &quot; + kid.name);<br></td></tr
><tr
id=sl_svn7768_303

><td class="source">//        }<br></td></tr
><tr
id=sl_svn7768_304

><td class="source">        addChild(kid);<br></td></tr
><tr
id=sl_svn7768_305

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_306

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_307

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_308

><td class="source"><br></td></tr
><tr
id=sl_svn7768_309

><td class="source"><br></td></tr
><tr
id=sl_svn7768_310

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_311

><td class="source">   * Parse a child XML element.<br></td></tr
><tr
id=sl_svn7768_312

><td class="source">   * Override this method to add parsing for more SVG elements.<br></td></tr
><tr
id=sl_svn7768_313

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_314

><td class="source">  protected PShape parseChild(XMLElement elem) {<br></td></tr
><tr
id=sl_svn7768_315

><td class="source">    String name = elem.getName();<br></td></tr
><tr
id=sl_svn7768_316

><td class="source">    PShapeSVG shape = null;<br></td></tr
><tr
id=sl_svn7768_317

><td class="source"><br></td></tr
><tr
id=sl_svn7768_318

><td class="source">    if (name.equals(&quot;g&quot;)) {<br></td></tr
><tr
id=sl_svn7768_319

><td class="source">      //return new BaseObject(this, elem);<br></td></tr
><tr
id=sl_svn7768_320

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_321

><td class="source"><br></td></tr
><tr
id=sl_svn7768_322

><td class="source">    } else if (name.equals(&quot;defs&quot;)) {<br></td></tr
><tr
id=sl_svn7768_323

><td class="source">      // generally this will contain gradient info, so may<br></td></tr
><tr
id=sl_svn7768_324

><td class="source">      // as well just throw it into a group element for parsing<br></td></tr
><tr
id=sl_svn7768_325

><td class="source">      //return new BaseObject(this, elem);<br></td></tr
><tr
id=sl_svn7768_326

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_327

><td class="source"><br></td></tr
><tr
id=sl_svn7768_328

><td class="source">    } else if (name.equals(&quot;line&quot;)) {<br></td></tr
><tr
id=sl_svn7768_329

><td class="source">      //return new Line(this, elem);<br></td></tr
><tr
id=sl_svn7768_330

><td class="source">      //return new BaseObject(this, elem, LINE);<br></td></tr
><tr
id=sl_svn7768_331

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_332

><td class="source">      shape.parseLine();<br></td></tr
><tr
id=sl_svn7768_333

><td class="source"><br></td></tr
><tr
id=sl_svn7768_334

><td class="source">    } else if (name.equals(&quot;circle&quot;)) {<br></td></tr
><tr
id=sl_svn7768_335

><td class="source">      //return new BaseObject(this, elem, ELLIPSE);<br></td></tr
><tr
id=sl_svn7768_336

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_337

><td class="source">      shape.parseEllipse(true);<br></td></tr
><tr
id=sl_svn7768_338

><td class="source"><br></td></tr
><tr
id=sl_svn7768_339

><td class="source">    } else if (name.equals(&quot;ellipse&quot;)) {<br></td></tr
><tr
id=sl_svn7768_340

><td class="source">      //return new BaseObject(this, elem, ELLIPSE);<br></td></tr
><tr
id=sl_svn7768_341

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_342

><td class="source">      shape.parseEllipse(false);<br></td></tr
><tr
id=sl_svn7768_343

><td class="source"><br></td></tr
><tr
id=sl_svn7768_344

><td class="source">    } else if (name.equals(&quot;rect&quot;)) {<br></td></tr
><tr
id=sl_svn7768_345

><td class="source">      //return new BaseObject(this, elem, RECT);<br></td></tr
><tr
id=sl_svn7768_346

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_347

><td class="source">      shape.parseRect();<br></td></tr
><tr
id=sl_svn7768_348

><td class="source"><br></td></tr
><tr
id=sl_svn7768_349

><td class="source">    } else if (name.equals(&quot;polygon&quot;)) {<br></td></tr
><tr
id=sl_svn7768_350

><td class="source">      //return new BaseObject(this, elem, POLYGON);<br></td></tr
><tr
id=sl_svn7768_351

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_352

><td class="source">      shape.parsePoly(true);<br></td></tr
><tr
id=sl_svn7768_353

><td class="source"><br></td></tr
><tr
id=sl_svn7768_354

><td class="source">    } else if (name.equals(&quot;polyline&quot;)) {<br></td></tr
><tr
id=sl_svn7768_355

><td class="source">      //return new BaseObject(this, elem, POLYGON);<br></td></tr
><tr
id=sl_svn7768_356

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_357

><td class="source">      shape.parsePoly(false);<br></td></tr
><tr
id=sl_svn7768_358

><td class="source"><br></td></tr
><tr
id=sl_svn7768_359

><td class="source">    } else if (name.equals(&quot;path&quot;)) {<br></td></tr
><tr
id=sl_svn7768_360

><td class="source">      //return new BaseObject(this, elem, PATH);<br></td></tr
><tr
id=sl_svn7768_361

><td class="source">      shape = new PShapeSVG(this, elem);<br></td></tr
><tr
id=sl_svn7768_362

><td class="source">      shape.parsePath();<br></td></tr
><tr
id=sl_svn7768_363

><td class="source"><br></td></tr
><tr
id=sl_svn7768_364

><td class="source">    } else if (name.equals(&quot;radialGradient&quot;)) {<br></td></tr
><tr
id=sl_svn7768_365

><td class="source">      return new RadialGradient(this, elem);<br></td></tr
><tr
id=sl_svn7768_366

><td class="source"><br></td></tr
><tr
id=sl_svn7768_367

><td class="source">    } else if (name.equals(&quot;linearGradient&quot;)) {<br></td></tr
><tr
id=sl_svn7768_368

><td class="source">      return new LinearGradient(this, elem);<br></td></tr
><tr
id=sl_svn7768_369

><td class="source"><br></td></tr
><tr
id=sl_svn7768_370

><td class="source">    } else if (name.equals(&quot;text&quot;) || name.equals(&quot;font&quot;)) {<br></td></tr
><tr
id=sl_svn7768_371

><td class="source">      PGraphics.showWarning(&quot;Text and fonts in SVG files &quot; +<br></td></tr
><tr
id=sl_svn7768_372

><td class="source">      		                  &quot;are not currently supported, &quot; +<br></td></tr
><tr
id=sl_svn7768_373

><td class="source">                            &quot;convert text to outlines instead.&quot;);<br></td></tr
><tr
id=sl_svn7768_374

><td class="source"><br></td></tr
><tr
id=sl_svn7768_375

><td class="source">    } else if (name.equals(&quot;filter&quot;)) {<br></td></tr
><tr
id=sl_svn7768_376

><td class="source">      PGraphics.showWarning(&quot;Filters are not supported.&quot;);<br></td></tr
><tr
id=sl_svn7768_377

><td class="source"><br></td></tr
><tr
id=sl_svn7768_378

><td class="source">    } else if (name.equals(&quot;mask&quot;)) {<br></td></tr
><tr
id=sl_svn7768_379

><td class="source">      PGraphics.showWarning(&quot;Masks are not supported.&quot;);<br></td></tr
><tr
id=sl_svn7768_380

><td class="source"><br></td></tr
><tr
id=sl_svn7768_381

><td class="source">    } else if (name.equals(&quot;pattern&quot;)) {<br></td></tr
><tr
id=sl_svn7768_382

><td class="source">      PGraphics.showWarning(&quot;Patterns are not supported.&quot;);<br></td></tr
><tr
id=sl_svn7768_383

><td class="source"><br></td></tr
><tr
id=sl_svn7768_384

><td class="source">    } else if (name.equals(&quot;stop&quot;)) {<br></td></tr
><tr
id=sl_svn7768_385

><td class="source">      // stop tag is handled by gradient parser, so don&#39;t warn about it<br></td></tr
><tr
id=sl_svn7768_386

><td class="source">      <br></td></tr
><tr
id=sl_svn7768_387

><td class="source">    } else if (name.equals(&quot;sodipodi:namedview&quot;)) {<br></td></tr
><tr
id=sl_svn7768_388

><td class="source">      // these are always in Inkscape files, the warnings get tedious  <br></td></tr
><tr
id=sl_svn7768_389

><td class="source">      <br></td></tr
><tr
id=sl_svn7768_390

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn7768_391

><td class="source">      PGraphics.showWarning(&quot;Ignoring  &lt;&quot; + name + &quot;&gt; tag.&quot;);<br></td></tr
><tr
id=sl_svn7768_392

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_393

><td class="source">    return shape;<br></td></tr
><tr
id=sl_svn7768_394

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_395

><td class="source"><br></td></tr
><tr
id=sl_svn7768_396

><td class="source"><br></td></tr
><tr
id=sl_svn7768_397

><td class="source">  protected void parseLine() {<br></td></tr
><tr
id=sl_svn7768_398

><td class="source">    primitive = LINE;<br></td></tr
><tr
id=sl_svn7768_399

><td class="source">    family = PRIMITIVE;<br></td></tr
><tr
id=sl_svn7768_400

><td class="source">    params = new float[] {<br></td></tr
><tr
id=sl_svn7768_401

><td class="source">      getFloatWithUnit(element, &quot;x1&quot;),<br></td></tr
><tr
id=sl_svn7768_402

><td class="source">      getFloatWithUnit(element, &quot;y1&quot;),<br></td></tr
><tr
id=sl_svn7768_403

><td class="source">      getFloatWithUnit(element, &quot;x2&quot;),<br></td></tr
><tr
id=sl_svn7768_404

><td class="source">      getFloatWithUnit(element, &quot;y2&quot;)<br></td></tr
><tr
id=sl_svn7768_405

><td class="source">    };<br></td></tr
><tr
id=sl_svn7768_406

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_407

><td class="source"><br></td></tr
><tr
id=sl_svn7768_408

><td class="source"><br></td></tr
><tr
id=sl_svn7768_409

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_410

><td class="source">   * Handles parsing ellipse and circle tags.<br></td></tr
><tr
id=sl_svn7768_411

><td class="source">   * @param circle true if this is a circle and not an ellipse<br></td></tr
><tr
id=sl_svn7768_412

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_413

><td class="source">  protected void parseEllipse(boolean circle) {<br></td></tr
><tr
id=sl_svn7768_414

><td class="source">    primitive = ELLIPSE;<br></td></tr
><tr
id=sl_svn7768_415

><td class="source">    family = PRIMITIVE;<br></td></tr
><tr
id=sl_svn7768_416

><td class="source">    params = new float[4];<br></td></tr
><tr
id=sl_svn7768_417

><td class="source"><br></td></tr
><tr
id=sl_svn7768_418

><td class="source">    params[0] = getFloatWithUnit(element, &quot;cx&quot;);<br></td></tr
><tr
id=sl_svn7768_419

><td class="source">    params[1] = getFloatWithUnit(element, &quot;cy&quot;);<br></td></tr
><tr
id=sl_svn7768_420

><td class="source"><br></td></tr
><tr
id=sl_svn7768_421

><td class="source">    float rx, ry;<br></td></tr
><tr
id=sl_svn7768_422

><td class="source">    if (circle) {<br></td></tr
><tr
id=sl_svn7768_423

><td class="source">      rx = ry = getFloatWithUnit(element, &quot;r&quot;);<br></td></tr
><tr
id=sl_svn7768_424

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn7768_425

><td class="source">      rx = getFloatWithUnit(element, &quot;rx&quot;);<br></td></tr
><tr
id=sl_svn7768_426

><td class="source">      ry = getFloatWithUnit(element, &quot;ry&quot;);<br></td></tr
><tr
id=sl_svn7768_427

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_428

><td class="source">    params[0] -= rx;<br></td></tr
><tr
id=sl_svn7768_429

><td class="source">    params[1] -= ry;<br></td></tr
><tr
id=sl_svn7768_430

><td class="source"><br></td></tr
><tr
id=sl_svn7768_431

><td class="source">    params[2] = rx*2;<br></td></tr
><tr
id=sl_svn7768_432

><td class="source">    params[3] = ry*2;<br></td></tr
><tr
id=sl_svn7768_433

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_434

><td class="source"><br></td></tr
><tr
id=sl_svn7768_435

><td class="source"><br></td></tr
><tr
id=sl_svn7768_436

><td class="source">  protected void parseRect() {<br></td></tr
><tr
id=sl_svn7768_437

><td class="source">    primitive = RECT;<br></td></tr
><tr
id=sl_svn7768_438

><td class="source">    family = PRIMITIVE;<br></td></tr
><tr
id=sl_svn7768_439

><td class="source">    params = new float[] {<br></td></tr
><tr
id=sl_svn7768_440

><td class="source">      getFloatWithUnit(element, &quot;x&quot;),<br></td></tr
><tr
id=sl_svn7768_441

><td class="source">      getFloatWithUnit(element, &quot;y&quot;),<br></td></tr
><tr
id=sl_svn7768_442

><td class="source">      getFloatWithUnit(element, &quot;width&quot;),<br></td></tr
><tr
id=sl_svn7768_443

><td class="source">      getFloatWithUnit(element, &quot;height&quot;)<br></td></tr
><tr
id=sl_svn7768_444

><td class="source">    };<br></td></tr
><tr
id=sl_svn7768_445

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_446

><td class="source"><br></td></tr
><tr
id=sl_svn7768_447

><td class="source"><br></td></tr
><tr
id=sl_svn7768_448

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_449

><td class="source">   * Parse a polyline or polygon from an SVG file.<br></td></tr
><tr
id=sl_svn7768_450

><td class="source">   * @param close true if shape is closed (polygon), false if not (polyline)<br></td></tr
><tr
id=sl_svn7768_451

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_452

><td class="source">  protected void parsePoly(boolean close) {<br></td></tr
><tr
id=sl_svn7768_453

><td class="source">    family = PATH;<br></td></tr
><tr
id=sl_svn7768_454

><td class="source">    this.close = close;<br></td></tr
><tr
id=sl_svn7768_455

><td class="source"><br></td></tr
><tr
id=sl_svn7768_456

><td class="source">    String pointsAttr = element.getString(&quot;points&quot;);<br></td></tr
><tr
id=sl_svn7768_457

><td class="source">    if (pointsAttr != null) {<br></td></tr
><tr
id=sl_svn7768_458

><td class="source">      String[] pointsBuffer = PApplet.splitTokens(pointsAttr);<br></td></tr
><tr
id=sl_svn7768_459

><td class="source">      vertexCount = pointsBuffer.length;<br></td></tr
><tr
id=sl_svn7768_460

><td class="source">      vertices = new float[vertexCount][2];<br></td></tr
><tr
id=sl_svn7768_461

><td class="source">      for (int i = 0; i &lt; vertexCount; i++) {<br></td></tr
><tr
id=sl_svn7768_462

><td class="source">        String pb[] = PApplet.split(pointsBuffer[i], &#39;,&#39;);<br></td></tr
><tr
id=sl_svn7768_463

><td class="source">        vertices[i][X] = Float.valueOf(pb[0]).floatValue();<br></td></tr
><tr
id=sl_svn7768_464

><td class="source">        vertices[i][Y] = Float.valueOf(pb[1]).floatValue();<br></td></tr
><tr
id=sl_svn7768_465

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_466

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_467

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_468

><td class="source"><br></td></tr
><tr
id=sl_svn7768_469

><td class="source"><br></td></tr
><tr
id=sl_svn7768_470

><td class="source">  protected void parsePath() {<br></td></tr
><tr
id=sl_svn7768_471

><td class="source">    family = PATH;<br></td></tr
><tr
id=sl_svn7768_472

><td class="source">    primitive = 0;<br></td></tr
><tr
id=sl_svn7768_473

><td class="source"><br></td></tr
><tr
id=sl_svn7768_474

><td class="source">    String pathData = element.getString(&quot;d&quot;);<br></td></tr
><tr
id=sl_svn7768_475

><td class="source">    if (pathData == null) return;<br></td></tr
><tr
id=sl_svn7768_476

><td class="source">    char[] pathDataChars = pathData.toCharArray();<br></td></tr
><tr
id=sl_svn7768_477

><td class="source"><br></td></tr
><tr
id=sl_svn7768_478

><td class="source">    StringBuffer pathBuffer = new StringBuffer();<br></td></tr
><tr
id=sl_svn7768_479

><td class="source">    boolean lastSeparate = false;<br></td></tr
><tr
id=sl_svn7768_480

><td class="source"><br></td></tr
><tr
id=sl_svn7768_481

><td class="source">    for (int i = 0; i &lt; pathDataChars.length; i++) {<br></td></tr
><tr
id=sl_svn7768_482

><td class="source">      char c = pathDataChars[i];<br></td></tr
><tr
id=sl_svn7768_483

><td class="source">      boolean separate = false;<br></td></tr
><tr
id=sl_svn7768_484

><td class="source"><br></td></tr
><tr
id=sl_svn7768_485

><td class="source">      if (c == &#39;M&#39; || c == &#39;m&#39; ||<br></td></tr
><tr
id=sl_svn7768_486

><td class="source">          c == &#39;L&#39; || c == &#39;l&#39; ||<br></td></tr
><tr
id=sl_svn7768_487

><td class="source">          c == &#39;H&#39; || c == &#39;h&#39; ||<br></td></tr
><tr
id=sl_svn7768_488

><td class="source">          c == &#39;V&#39; || c == &#39;v&#39; ||<br></td></tr
><tr
id=sl_svn7768_489

><td class="source">          c == &#39;C&#39; || c == &#39;c&#39; ||  // beziers<br></td></tr
><tr
id=sl_svn7768_490

><td class="source">          c == &#39;S&#39; || c == &#39;s&#39; ||<br></td></tr
><tr
id=sl_svn7768_491

><td class="source">          c == &#39;Q&#39; || c == &#39;q&#39; ||  // quadratic beziers<br></td></tr
><tr
id=sl_svn7768_492

><td class="source">          c == &#39;T&#39; || c == &#39;t&#39; ||<br></td></tr
><tr
id=sl_svn7768_493

><td class="source">          c == &#39;Z&#39; || c == &#39;z&#39; ||  // closepath<br></td></tr
><tr
id=sl_svn7768_494

><td class="source">          c == &#39;,&#39;) {<br></td></tr
><tr
id=sl_svn7768_495

><td class="source">        separate = true;<br></td></tr
><tr
id=sl_svn7768_496

><td class="source">        if (i != 0) {<br></td></tr
><tr
id=sl_svn7768_497

><td class="source">          pathBuffer.append(&quot;|&quot;);<br></td></tr
><tr
id=sl_svn7768_498

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_499

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_500

><td class="source">      if (c == &#39;Z&#39; || c == &#39;z&#39;) {<br></td></tr
><tr
id=sl_svn7768_501

><td class="source">        separate = false;<br></td></tr
><tr
id=sl_svn7768_502

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_503

><td class="source">      if (c == &#39;-&#39; &amp;&amp; !lastSeparate) {<br></td></tr
><tr
id=sl_svn7768_504

><td class="source">        // allow for &#39;e&#39; notation in numbers, e.g. 2.10e-9 <br></td></tr
><tr
id=sl_svn7768_505

><td class="source">        // http://dev.processing.org/bugs/show_bug.cgi?id=1408<br></td></tr
><tr
id=sl_svn7768_506

><td class="source">        if (i == 0 || pathDataChars[i-1] != &#39;e&#39;) {<br></td></tr
><tr
id=sl_svn7768_507

><td class="source">          pathBuffer.append(&quot;|&quot;);<br></td></tr
><tr
id=sl_svn7768_508

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_509

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_510

><td class="source">      if (c != &#39;,&#39;) {<br></td></tr
><tr
id=sl_svn7768_511

><td class="source">        pathBuffer.append(c); //&quot;&quot; + pathDataBuffer.charAt(i));<br></td></tr
><tr
id=sl_svn7768_512

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_513

><td class="source">      if (separate &amp;&amp; c != &#39;,&#39; &amp;&amp; c != &#39;-&#39;) {<br></td></tr
><tr
id=sl_svn7768_514

><td class="source">        pathBuffer.append(&quot;|&quot;);<br></td></tr
><tr
id=sl_svn7768_515

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_516

><td class="source">      lastSeparate = separate;<br></td></tr
><tr
id=sl_svn7768_517

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_518

><td class="source"><br></td></tr
><tr
id=sl_svn7768_519

><td class="source">    // use whitespace constant to get rid of extra spaces and CR or LF<br></td></tr
><tr
id=sl_svn7768_520

><td class="source">    String[] pathDataKeys =<br></td></tr
><tr
id=sl_svn7768_521

><td class="source">      PApplet.splitTokens(pathBuffer.toString(), &quot;|&quot; + WHITESPACE);<br></td></tr
><tr
id=sl_svn7768_522

><td class="source">    vertices = new float[pathDataKeys.length][2];<br></td></tr
><tr
id=sl_svn7768_523

><td class="source">    vertexCodes = new int[pathDataKeys.length];<br></td></tr
><tr
id=sl_svn7768_524

><td class="source"><br></td></tr
><tr
id=sl_svn7768_525

><td class="source">    float cx = 0;<br></td></tr
><tr
id=sl_svn7768_526

><td class="source">    float cy = 0;<br></td></tr
><tr
id=sl_svn7768_527

><td class="source">    int i = 0;<br></td></tr
><tr
id=sl_svn7768_528

><td class="source"><br></td></tr
><tr
id=sl_svn7768_529

><td class="source">    char implicitCommand = &#39;\0&#39;;<br></td></tr
><tr
id=sl_svn7768_530

><td class="source"><br></td></tr
><tr
id=sl_svn7768_531

><td class="source">    while (i &lt; pathDataKeys.length) {<br></td></tr
><tr
id=sl_svn7768_532

><td class="source">      char c = pathDataKeys[i].charAt(0);<br></td></tr
><tr
id=sl_svn7768_533

><td class="source">      if(((c &gt;= &#39;0&#39; &amp;&amp; c &lt;= &#39;9&#39;) || (c == &#39;-&#39;)) &amp;&amp; implicitCommand != &#39;\0&#39;) {<br></td></tr
><tr
id=sl_svn7768_534

><td class="source">        c = implicitCommand;<br></td></tr
><tr
id=sl_svn7768_535

><td class="source">        i--;<br></td></tr
><tr
id=sl_svn7768_536

><td class="source">      } else {<br></td></tr
><tr
id=sl_svn7768_537

><td class="source">        implicitCommand = c;<br></td></tr
><tr
id=sl_svn7768_538

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_539

><td class="source">      switch (c) {<br></td></tr
><tr
id=sl_svn7768_540

><td class="source"><br></td></tr
><tr
id=sl_svn7768_541

><td class="source">      case &#39;M&#39;:  // M - move to (absolute)<br></td></tr
><tr
id=sl_svn7768_542

><td class="source">        cx = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_543

><td class="source">        cy = PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_544

><td class="source">        parsePathMoveto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_545

><td class="source">        implicitCommand = &#39;L&#39;;<br></td></tr
><tr
id=sl_svn7768_546

><td class="source">        i += 3;<br></td></tr
><tr
id=sl_svn7768_547

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_548

><td class="source"><br></td></tr
><tr
id=sl_svn7768_549

><td class="source">      case &#39;m&#39;:  // m - move to (relative)<br></td></tr
><tr
id=sl_svn7768_550

><td class="source">        cx = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_551

><td class="source">        cy = cy + PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_552

><td class="source">        parsePathMoveto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_553

><td class="source">        implicitCommand = &#39;l&#39;;<br></td></tr
><tr
id=sl_svn7768_554

><td class="source">        i += 3;<br></td></tr
><tr
id=sl_svn7768_555

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_556

><td class="source"><br></td></tr
><tr
id=sl_svn7768_557

><td class="source">      case &#39;L&#39;:<br></td></tr
><tr
id=sl_svn7768_558

><td class="source">        cx = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_559

><td class="source">        cy = PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_560

><td class="source">        parsePathLineto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_561

><td class="source">        i += 3;<br></td></tr
><tr
id=sl_svn7768_562

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_563

><td class="source"><br></td></tr
><tr
id=sl_svn7768_564

><td class="source">      case &#39;l&#39;:<br></td></tr
><tr
id=sl_svn7768_565

><td class="source">        cx = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_566

><td class="source">        cy = cy + PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_567

><td class="source">        parsePathLineto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_568

><td class="source">        i += 3;<br></td></tr
><tr
id=sl_svn7768_569

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_570

><td class="source"><br></td></tr
><tr
id=sl_svn7768_571

><td class="source">        // horizontal lineto absolute<br></td></tr
><tr
id=sl_svn7768_572

><td class="source">      case &#39;H&#39;:<br></td></tr
><tr
id=sl_svn7768_573

><td class="source">        cx = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_574

><td class="source">        parsePathLineto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_575

><td class="source">        i += 2;<br></td></tr
><tr
id=sl_svn7768_576

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_577

><td class="source"><br></td></tr
><tr
id=sl_svn7768_578

><td class="source">        // horizontal lineto relative<br></td></tr
><tr
id=sl_svn7768_579

><td class="source">      case &#39;h&#39;:<br></td></tr
><tr
id=sl_svn7768_580

><td class="source">        cx = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_581

><td class="source">        parsePathLineto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_582

><td class="source">        i += 2;<br></td></tr
><tr
id=sl_svn7768_583

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_584

><td class="source"><br></td></tr
><tr
id=sl_svn7768_585

><td class="source">      case &#39;V&#39;:<br></td></tr
><tr
id=sl_svn7768_586

><td class="source">        cy = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_587

><td class="source">        parsePathLineto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_588

><td class="source">        i += 2;<br></td></tr
><tr
id=sl_svn7768_589

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_590

><td class="source"><br></td></tr
><tr
id=sl_svn7768_591

><td class="source">      case &#39;v&#39;:<br></td></tr
><tr
id=sl_svn7768_592

><td class="source">        cy = cy + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_593

><td class="source">        parsePathLineto(cx, cy);<br></td></tr
><tr
id=sl_svn7768_594

><td class="source">        i += 2;<br></td></tr
><tr
id=sl_svn7768_595

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_596

><td class="source"><br></td></tr
><tr
id=sl_svn7768_597

><td class="source">        // C - curve to (absolute)<br></td></tr
><tr
id=sl_svn7768_598

><td class="source">      case &#39;C&#39;: {<br></td></tr
><tr
id=sl_svn7768_599

><td class="source">        float ctrlX1 = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_600

><td class="source">        float ctrlY1 = PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_601

><td class="source">        float ctrlX2 = PApplet.parseFloat(pathDataKeys[i + 3]);<br></td></tr
><tr
id=sl_svn7768_602

><td class="source">        float ctrlY2 = PApplet.parseFloat(pathDataKeys[i + 4]);<br></td></tr
><tr
id=sl_svn7768_603

><td class="source">        float endX = PApplet.parseFloat(pathDataKeys[i + 5]);<br></td></tr
><tr
id=sl_svn7768_604

><td class="source">        float endY = PApplet.parseFloat(pathDataKeys[i + 6]);<br></td></tr
><tr
id=sl_svn7768_605

><td class="source">        parsePathCurveto(ctrlX1, ctrlY1, ctrlX2, ctrlY2, endX, endY);<br></td></tr
><tr
id=sl_svn7768_606

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_607

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_608

><td class="source">        i += 7;<br></td></tr
><tr
id=sl_svn7768_609

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_610

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_611

><td class="source"><br></td></tr
><tr
id=sl_svn7768_612

><td class="source">        // c - curve to (relative)<br></td></tr
><tr
id=sl_svn7768_613

><td class="source">      case &#39;c&#39;: {<br></td></tr
><tr
id=sl_svn7768_614

><td class="source">        float ctrlX1 = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_615

><td class="source">        float ctrlY1 = cy + PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_616

><td class="source">        float ctrlX2 = cx + PApplet.parseFloat(pathDataKeys[i + 3]);<br></td></tr
><tr
id=sl_svn7768_617

><td class="source">        float ctrlY2 = cy + PApplet.parseFloat(pathDataKeys[i + 4]);<br></td></tr
><tr
id=sl_svn7768_618

><td class="source">        float endX = cx + PApplet.parseFloat(pathDataKeys[i + 5]);<br></td></tr
><tr
id=sl_svn7768_619

><td class="source">        float endY = cy + PApplet.parseFloat(pathDataKeys[i + 6]);<br></td></tr
><tr
id=sl_svn7768_620

><td class="source">        parsePathCurveto(ctrlX1, ctrlY1, ctrlX2, ctrlY2, endX, endY);<br></td></tr
><tr
id=sl_svn7768_621

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_622

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_623

><td class="source">        i += 7;<br></td></tr
><tr
id=sl_svn7768_624

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_625

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_626

><td class="source"><br></td></tr
><tr
id=sl_svn7768_627

><td class="source">        // S - curve to shorthand (absolute)<br></td></tr
><tr
id=sl_svn7768_628

><td class="source">      case &#39;S&#39;: {<br></td></tr
><tr
id=sl_svn7768_629

><td class="source">        float ppx = vertices[vertexCount-2][X];<br></td></tr
><tr
id=sl_svn7768_630

><td class="source">        float ppy = vertices[vertexCount-2][Y];<br></td></tr
><tr
id=sl_svn7768_631

><td class="source">        float px = vertices[vertexCount-1][X];<br></td></tr
><tr
id=sl_svn7768_632

><td class="source">        float py = vertices[vertexCount-1][Y];<br></td></tr
><tr
id=sl_svn7768_633

><td class="source">        float ctrlX1 = px + (px - ppx);<br></td></tr
><tr
id=sl_svn7768_634

><td class="source">        float ctrlY1 = py + (py - ppy);<br></td></tr
><tr
id=sl_svn7768_635

><td class="source">        float ctrlX2 = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_636

><td class="source">        float ctrlY2 = PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_637

><td class="source">        float endX = PApplet.parseFloat(pathDataKeys[i + 3]);<br></td></tr
><tr
id=sl_svn7768_638

><td class="source">        float endY = PApplet.parseFloat(pathDataKeys[i + 4]);<br></td></tr
><tr
id=sl_svn7768_639

><td class="source">        parsePathCurveto(ctrlX1, ctrlY1, ctrlX2, ctrlY2, endX, endY);<br></td></tr
><tr
id=sl_svn7768_640

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_641

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_642

><td class="source">        i += 5;<br></td></tr
><tr
id=sl_svn7768_643

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_644

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_645

><td class="source"><br></td></tr
><tr
id=sl_svn7768_646

><td class="source">        // s - curve to shorthand (relative)<br></td></tr
><tr
id=sl_svn7768_647

><td class="source">      case &#39;s&#39;: {<br></td></tr
><tr
id=sl_svn7768_648

><td class="source">        float ppx = vertices[vertexCount-2][X];<br></td></tr
><tr
id=sl_svn7768_649

><td class="source">        float ppy = vertices[vertexCount-2][Y];<br></td></tr
><tr
id=sl_svn7768_650

><td class="source">        float px = vertices[vertexCount-1][X];<br></td></tr
><tr
id=sl_svn7768_651

><td class="source">        float py = vertices[vertexCount-1][Y];<br></td></tr
><tr
id=sl_svn7768_652

><td class="source">        float ctrlX1 = px + (px - ppx);<br></td></tr
><tr
id=sl_svn7768_653

><td class="source">        float ctrlY1 = py + (py - ppy);<br></td></tr
><tr
id=sl_svn7768_654

><td class="source">        float ctrlX2 = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_655

><td class="source">        float ctrlY2 = cy + PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_656

><td class="source">        float endX = cx + PApplet.parseFloat(pathDataKeys[i + 3]);<br></td></tr
><tr
id=sl_svn7768_657

><td class="source">        float endY = cy + PApplet.parseFloat(pathDataKeys[i + 4]);<br></td></tr
><tr
id=sl_svn7768_658

><td class="source">        parsePathCurveto(ctrlX1, ctrlY1, ctrlX2, ctrlY2, endX, endY);<br></td></tr
><tr
id=sl_svn7768_659

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_660

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_661

><td class="source">        i += 5;<br></td></tr
><tr
id=sl_svn7768_662

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_663

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_664

><td class="source"><br></td></tr
><tr
id=sl_svn7768_665

><td class="source">        // Q - quadratic curve to (absolute)<br></td></tr
><tr
id=sl_svn7768_666

><td class="source">      case &#39;Q&#39;: {<br></td></tr
><tr
id=sl_svn7768_667

><td class="source">        float ctrlX = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_668

><td class="source">        float ctrlY = PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_669

><td class="source">        float endX = PApplet.parseFloat(pathDataKeys[i + 3]);<br></td></tr
><tr
id=sl_svn7768_670

><td class="source">        float endY = PApplet.parseFloat(pathDataKeys[i + 4]);<br></td></tr
><tr
id=sl_svn7768_671

><td class="source">        parsePathQuadto(cx, cy, ctrlX, ctrlY, endX, endY);<br></td></tr
><tr
id=sl_svn7768_672

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_673

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_674

><td class="source">        i += 5;<br></td></tr
><tr
id=sl_svn7768_675

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_676

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_677

><td class="source"><br></td></tr
><tr
id=sl_svn7768_678

><td class="source">        // q - quadratic curve to (relative)<br></td></tr
><tr
id=sl_svn7768_679

><td class="source">      case &#39;q&#39;: {<br></td></tr
><tr
id=sl_svn7768_680

><td class="source">        float ctrlX = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_681

><td class="source">        float ctrlY = cy + PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_682

><td class="source">        float endX = cx + PApplet.parseFloat(pathDataKeys[i + 3]);<br></td></tr
><tr
id=sl_svn7768_683

><td class="source">        float endY = cy + PApplet.parseFloat(pathDataKeys[i + 4]);<br></td></tr
><tr
id=sl_svn7768_684

><td class="source">        parsePathQuadto(cx, cy, ctrlX, ctrlY, endX, endY);<br></td></tr
><tr
id=sl_svn7768_685

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_686

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_687

><td class="source">        i += 5;<br></td></tr
><tr
id=sl_svn7768_688

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_689

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_690

><td class="source"><br></td></tr
><tr
id=sl_svn7768_691

><td class="source">        // T - quadratic curve to shorthand (absolute)<br></td></tr
><tr
id=sl_svn7768_692

><td class="source">        // The control point is assumed to be the reflection of the<br></td></tr
><tr
id=sl_svn7768_693

><td class="source">        // control point on the previous command relative to the<br></td></tr
><tr
id=sl_svn7768_694

><td class="source">        // current point. (If there is no previous command or if the<br></td></tr
><tr
id=sl_svn7768_695

><td class="source">        // previous command was not a Q, q, T or t, assume the control<br></td></tr
><tr
id=sl_svn7768_696

><td class="source">        // point is coincident with the current point.)<br></td></tr
><tr
id=sl_svn7768_697

><td class="source">      case &#39;T&#39;: {<br></td></tr
><tr
id=sl_svn7768_698

><td class="source">        float ppx = vertices[vertexCount-2][X];<br></td></tr
><tr
id=sl_svn7768_699

><td class="source">        float ppy = vertices[vertexCount-2][Y];<br></td></tr
><tr
id=sl_svn7768_700

><td class="source">        float px = vertices[vertexCount-1][X];<br></td></tr
><tr
id=sl_svn7768_701

><td class="source">        float py = vertices[vertexCount-1][Y];<br></td></tr
><tr
id=sl_svn7768_702

><td class="source">        float ctrlX = px + (px - ppx);<br></td></tr
><tr
id=sl_svn7768_703

><td class="source">        float ctrlY = py + (py - ppy);<br></td></tr
><tr
id=sl_svn7768_704

><td class="source">        float endX = PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_705

><td class="source">        float endY = PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_706

><td class="source">        parsePathQuadto(cx, cy, ctrlX, ctrlY, endX, endY);<br></td></tr
><tr
id=sl_svn7768_707

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_708

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_709

><td class="source">        i += 3;<br></td></tr
><tr
id=sl_svn7768_710

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_711

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_712

><td class="source"><br></td></tr
><tr
id=sl_svn7768_713

><td class="source">        // t - quadratic curve to shorthand (relative)<br></td></tr
><tr
id=sl_svn7768_714

><td class="source">      case &#39;t&#39;: {<br></td></tr
><tr
id=sl_svn7768_715

><td class="source">        float ppx = vertices[vertexCount-2][X];<br></td></tr
><tr
id=sl_svn7768_716

><td class="source">        float ppy = vertices[vertexCount-2][Y];<br></td></tr
><tr
id=sl_svn7768_717

><td class="source">        float px = vertices[vertexCount-1][X];<br></td></tr
><tr
id=sl_svn7768_718

><td class="source">        float py = vertices[vertexCount-1][Y];<br></td></tr
><tr
id=sl_svn7768_719

><td class="source">        float ctrlX = px + (px - ppx);<br></td></tr
><tr
id=sl_svn7768_720

><td class="source">        float ctrlY = py + (py - ppy);<br></td></tr
><tr
id=sl_svn7768_721

><td class="source">        float endX = cx + PApplet.parseFloat(pathDataKeys[i + 1]);<br></td></tr
><tr
id=sl_svn7768_722

><td class="source">        float endY = cy + PApplet.parseFloat(pathDataKeys[i + 2]);<br></td></tr
><tr
id=sl_svn7768_723

><td class="source">        parsePathQuadto(cx, cy, ctrlX, ctrlY, endX, endY);<br></td></tr
><tr
id=sl_svn7768_724

><td class="source">        cx = endX;<br></td></tr
><tr
id=sl_svn7768_725

><td class="source">        cy = endY;<br></td></tr
><tr
id=sl_svn7768_726

><td class="source">        i += 3;<br></td></tr
><tr
id=sl_svn7768_727

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_728

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_729

><td class="source"><br></td></tr
><tr
id=sl_svn7768_730

><td class="source">      case &#39;Z&#39;:<br></td></tr
><tr
id=sl_svn7768_731

><td class="source">      case &#39;z&#39;:<br></td></tr
><tr
id=sl_svn7768_732

><td class="source">        close = true;<br></td></tr
><tr
id=sl_svn7768_733

><td class="source">        i++;<br></td></tr
><tr
id=sl_svn7768_734

><td class="source">        break;<br></td></tr
><tr
id=sl_svn7768_735

><td class="source"><br></td></tr
><tr
id=sl_svn7768_736

><td class="source">      default:<br></td></tr
><tr
id=sl_svn7768_737

><td class="source">        String parsed =<br></td></tr
><tr
id=sl_svn7768_738

><td class="source">          PApplet.join(PApplet.subset(pathDataKeys, 0, i), &quot;,&quot;);<br></td></tr
><tr
id=sl_svn7768_739

><td class="source">        String unparsed =<br></td></tr
><tr
id=sl_svn7768_740

><td class="source">          PApplet.join(PApplet.subset(pathDataKeys, i), &quot;,&quot;);<br></td></tr
><tr
id=sl_svn7768_741

><td class="source">        System.err.println(&quot;parsed: &quot; + parsed);<br></td></tr
><tr
id=sl_svn7768_742

><td class="source">        System.err.println(&quot;unparsed: &quot; + unparsed);<br></td></tr
><tr
id=sl_svn7768_743

><td class="source">        if (pathDataKeys[i].equals(&quot;a&quot;) || pathDataKeys[i].equals(&quot;A&quot;)) {<br></td></tr
><tr
id=sl_svn7768_744

><td class="source">          String msg = &quot;Sorry, elliptical arc support for SVG files &quot; +<br></td></tr
><tr
id=sl_svn7768_745

><td class="source">            &quot;is not yet implemented (See bug #996 for details)&quot;;<br></td></tr
><tr
id=sl_svn7768_746

><td class="source">          throw new RuntimeException(msg);<br></td></tr
><tr
id=sl_svn7768_747

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_748

><td class="source">        throw new RuntimeException(&quot;shape command not handled: &quot; + pathDataKeys[i]);<br></td></tr
><tr
id=sl_svn7768_749

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_750

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_751

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_752

><td class="source"><br></td></tr
><tr
id=sl_svn7768_753

><td class="source"><br></td></tr
><tr
id=sl_svn7768_754

><td class="source">//      private void parsePathCheck(int num) {<br></td></tr
><tr
id=sl_svn7768_755

><td class="source">//        if (vertexCount + num-1 &gt;= vertices.length) {<br></td></tr
><tr
id=sl_svn7768_756

><td class="source">//          //vertices = (float[][]) PApplet.expand(vertices);<br></td></tr
><tr
id=sl_svn7768_757

><td class="source">//          float[][] temp = new float[vertexCount &lt;&lt; 1][2];<br></td></tr
><tr
id=sl_svn7768_758

><td class="source">//          System.arraycopy(vertices, 0, temp, 0, vertexCount);<br></td></tr
><tr
id=sl_svn7768_759

><td class="source">//          vertices = temp;<br></td></tr
><tr
id=sl_svn7768_760

><td class="source">//        }<br></td></tr
><tr
id=sl_svn7768_761

><td class="source">//      }<br></td></tr
><tr
id=sl_svn7768_762

><td class="source"><br></td></tr
><tr
id=sl_svn7768_763

><td class="source">  private void parsePathVertex(float x, float y) {<br></td></tr
><tr
id=sl_svn7768_764

><td class="source">    if (vertexCount == vertices.length) {<br></td></tr
><tr
id=sl_svn7768_765

><td class="source">      //vertices = (float[][]) PApplet.expand(vertices);<br></td></tr
><tr
id=sl_svn7768_766

><td class="source">      float[][] temp = new float[vertexCount &lt;&lt; 1][2];<br></td></tr
><tr
id=sl_svn7768_767

><td class="source">      System.arraycopy(vertices, 0, temp, 0, vertexCount);<br></td></tr
><tr
id=sl_svn7768_768

><td class="source">      vertices = temp;<br></td></tr
><tr
id=sl_svn7768_769

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_770

><td class="source">    vertices[vertexCount][X] = x;<br></td></tr
><tr
id=sl_svn7768_771

><td class="source">    vertices[vertexCount][Y] = y;<br></td></tr
><tr
id=sl_svn7768_772

><td class="source">    vertexCount++;<br></td></tr
><tr
id=sl_svn7768_773

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_774

><td class="source"><br></td></tr
><tr
id=sl_svn7768_775

><td class="source"><br></td></tr
><tr
id=sl_svn7768_776

><td class="source">  private void parsePathCode(int what) {<br></td></tr
><tr
id=sl_svn7768_777

><td class="source">    if (vertexCodeCount == vertexCodes.length) {<br></td></tr
><tr
id=sl_svn7768_778

><td class="source">      vertexCodes = PApplet.expand(vertexCodes);<br></td></tr
><tr
id=sl_svn7768_779

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_780

><td class="source">    vertexCodes[vertexCodeCount++] = what;<br></td></tr
><tr
id=sl_svn7768_781

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_782

><td class="source"><br></td></tr
><tr
id=sl_svn7768_783

><td class="source"><br></td></tr
><tr
id=sl_svn7768_784

><td class="source">  private void parsePathMoveto(float px, float py) {<br></td></tr
><tr
id=sl_svn7768_785

><td class="source">    if (vertexCount &gt; 0) {<br></td></tr
><tr
id=sl_svn7768_786

><td class="source">      parsePathCode(BREAK);<br></td></tr
><tr
id=sl_svn7768_787

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_788

><td class="source">    parsePathCode(VERTEX);<br></td></tr
><tr
id=sl_svn7768_789

><td class="source">    parsePathVertex(px, py);<br></td></tr
><tr
id=sl_svn7768_790

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_791

><td class="source"><br></td></tr
><tr
id=sl_svn7768_792

><td class="source"><br></td></tr
><tr
id=sl_svn7768_793

><td class="source">  private void parsePathLineto(float px, float py) {<br></td></tr
><tr
id=sl_svn7768_794

><td class="source">    parsePathCode(VERTEX);<br></td></tr
><tr
id=sl_svn7768_795

><td class="source">    parsePathVertex(px, py);<br></td></tr
><tr
id=sl_svn7768_796

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_797

><td class="source"><br></td></tr
><tr
id=sl_svn7768_798

><td class="source"><br></td></tr
><tr
id=sl_svn7768_799

><td class="source">  private void parsePathCurveto(float x1, float y1,<br></td></tr
><tr
id=sl_svn7768_800

><td class="source">                                float x2, float y2,<br></td></tr
><tr
id=sl_svn7768_801

><td class="source">                                float x3, float y3) {<br></td></tr
><tr
id=sl_svn7768_802

><td class="source">    parsePathCode(BEZIER_VERTEX);<br></td></tr
><tr
id=sl_svn7768_803

><td class="source">    parsePathVertex(x1, y1);<br></td></tr
><tr
id=sl_svn7768_804

><td class="source">    parsePathVertex(x2, y2);<br></td></tr
><tr
id=sl_svn7768_805

><td class="source">    parsePathVertex(x3, y3);<br></td></tr
><tr
id=sl_svn7768_806

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_807

><td class="source"><br></td></tr
><tr
id=sl_svn7768_808

><td class="source">  private void parsePathQuadto(float x1, float y1, <br></td></tr
><tr
id=sl_svn7768_809

><td class="source">                               float cx, float cy,<br></td></tr
><tr
id=sl_svn7768_810

><td class="source">                               float x2, float y2) {<br></td></tr
><tr
id=sl_svn7768_811

><td class="source">    parsePathCode(BEZIER_VERTEX);<br></td></tr
><tr
id=sl_svn7768_812

><td class="source">    // x1/y1 already covered by last moveto, lineto, or curveto<br></td></tr
><tr
id=sl_svn7768_813

><td class="source">    parsePathVertex(x1 + ((cx-x1)*2/3.0f), y1 + ((cy-y1)*2/3.0f));<br></td></tr
><tr
id=sl_svn7768_814

><td class="source">    parsePathVertex(x2 + ((cx-x2)*2/3.0f), y2 + ((cy-y2)*2/3.0f));<br></td></tr
><tr
id=sl_svn7768_815

><td class="source">    parsePathVertex(x2, y2);<br></td></tr
><tr
id=sl_svn7768_816

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_817

><td class="source"><br></td></tr
><tr
id=sl_svn7768_818

><td class="source"><br></td></tr
><tr
id=sl_svn7768_819

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_820

><td class="source">   * Parse the specified SVG matrix into a PMatrix2D. Note that PMatrix2D<br></td></tr
><tr
id=sl_svn7768_821

><td class="source">   * is rotated relative to the SVG definition, so parameters are rearranged<br></td></tr
><tr
id=sl_svn7768_822

><td class="source">   * here. More about the transformation matrices in<br></td></tr
><tr
id=sl_svn7768_823

><td class="source">   * &lt;a href=&quot;http://www.w3.org/TR/SVG/coords.html#TransformAttribute&quot;&gt;this section&lt;/a&gt;<br></td></tr
><tr
id=sl_svn7768_824

><td class="source">   * of the SVG documentation.<br></td></tr
><tr
id=sl_svn7768_825

><td class="source">   * @param matrixStr text of the matrix param.<br></td></tr
><tr
id=sl_svn7768_826

><td class="source">   * @return a good old-fashioned PMatrix2D<br></td></tr
><tr
id=sl_svn7768_827

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_828

><td class="source">  static protected PMatrix2D parseMatrix(String matrixStr) {<br></td></tr
><tr
id=sl_svn7768_829

><td class="source">    String[] pieces = PApplet.match(matrixStr, &quot;\\s*(\\w+)\\((.*)\\)&quot;);<br></td></tr
><tr
id=sl_svn7768_830

><td class="source">    if (pieces == null) {<br></td></tr
><tr
id=sl_svn7768_831

><td class="source">      System.err.println(&quot;Could not parse transform &quot; + matrixStr);<br></td></tr
><tr
id=sl_svn7768_832

><td class="source">      return null;<br></td></tr
><tr
id=sl_svn7768_833

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_834

><td class="source">    float[] m = PApplet.parseFloat(PApplet.splitTokens(pieces[2], &quot;, &quot;));<br></td></tr
><tr
id=sl_svn7768_835

><td class="source">    if (pieces[1].equals(&quot;matrix&quot;)) {<br></td></tr
><tr
id=sl_svn7768_836

><td class="source">      return new PMatrix2D(m[0], m[2], m[4], m[1], m[3], m[5]);<br></td></tr
><tr
id=sl_svn7768_837

><td class="source"><br></td></tr
><tr
id=sl_svn7768_838

><td class="source">    } else if (pieces[1].equals(&quot;translate&quot;)) {<br></td></tr
><tr
id=sl_svn7768_839

><td class="source">      float tx = m[0];<br></td></tr
><tr
id=sl_svn7768_840

><td class="source">      float ty = (m.length == 2) ? m[1] : m[0];<br></td></tr
><tr
id=sl_svn7768_841

><td class="source">      //return new float[] { 1, 0, tx,  0, 1, ty };<br></td></tr
><tr
id=sl_svn7768_842

><td class="source">      return new PMatrix2D(1, 0, tx, 0, 1, ty);<br></td></tr
><tr
id=sl_svn7768_843

><td class="source"><br></td></tr
><tr
id=sl_svn7768_844

><td class="source">    } else if (pieces[1].equals(&quot;scale&quot;)) {<br></td></tr
><tr
id=sl_svn7768_845

><td class="source">      float sx = m[0];<br></td></tr
><tr
id=sl_svn7768_846

><td class="source">      float sy = (m.length == 2) ? m[1] : m[0];<br></td></tr
><tr
id=sl_svn7768_847

><td class="source">      //return new float[] { sx, 0, 0, 0, sy, 0 };<br></td></tr
><tr
id=sl_svn7768_848

><td class="source">      return new PMatrix2D(sx, 0, 0,  0, sy, 0);<br></td></tr
><tr
id=sl_svn7768_849

><td class="source"><br></td></tr
><tr
id=sl_svn7768_850

><td class="source">    } else if (pieces[1].equals(&quot;rotate&quot;)) {<br></td></tr
><tr
id=sl_svn7768_851

><td class="source">      float angle = m[0];<br></td></tr
><tr
id=sl_svn7768_852

><td class="source"><br></td></tr
><tr
id=sl_svn7768_853

><td class="source">      if (m.length == 1) {<br></td></tr
><tr
id=sl_svn7768_854

><td class="source">        float c = PApplet.cos(angle);<br></td></tr
><tr
id=sl_svn7768_855

><td class="source">        float s = PApplet.sin(angle);<br></td></tr
><tr
id=sl_svn7768_856

><td class="source">        // SVG version is cos(a) sin(a) -sin(a) cos(a) 0 0<br></td></tr
><tr
id=sl_svn7768_857

><td class="source">        return new PMatrix2D(c, -s, 0, s, c, 0);<br></td></tr
><tr
id=sl_svn7768_858

><td class="source"><br></td></tr
><tr
id=sl_svn7768_859

><td class="source">      } else if (m.length == 3) {<br></td></tr
><tr
id=sl_svn7768_860

><td class="source">        PMatrix2D mat = new PMatrix2D(0, 1, m[1],  1, 0, m[2]);<br></td></tr
><tr
id=sl_svn7768_861

><td class="source">        mat.rotate(m[0]);<br></td></tr
><tr
id=sl_svn7768_862

><td class="source">        mat.translate(-m[1], -m[2]);<br></td></tr
><tr
id=sl_svn7768_863

><td class="source">        return mat; //.get(null);<br></td></tr
><tr
id=sl_svn7768_864

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_865

><td class="source"><br></td></tr
><tr
id=sl_svn7768_866

><td class="source">    } else if (pieces[1].equals(&quot;skewX&quot;)) {<br></td></tr
><tr
id=sl_svn7768_867

><td class="source">      return new PMatrix2D(1, 0, 1,  PApplet.tan(m[0]), 0, 0);<br></td></tr
><tr
id=sl_svn7768_868

><td class="source"><br></td></tr
><tr
id=sl_svn7768_869

><td class="source">    } else if (pieces[1].equals(&quot;skewY&quot;)) {<br></td></tr
><tr
id=sl_svn7768_870

><td class="source">      return new PMatrix2D(1, 0, 1,  0, PApplet.tan(m[0]), 0);<br></td></tr
><tr
id=sl_svn7768_871

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_872

><td class="source">    return null;<br></td></tr
><tr
id=sl_svn7768_873

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_874

><td class="source"><br></td></tr
><tr
id=sl_svn7768_875

><td class="source"><br></td></tr
><tr
id=sl_svn7768_876

><td class="source">  protected void parseColors(XMLElement properties) {<br></td></tr
><tr
id=sl_svn7768_877

><td class="source">    if (properties.hasAttribute(&quot;opacity&quot;)) {<br></td></tr
><tr
id=sl_svn7768_878

><td class="source">      String opacityText = properties.getString(&quot;opacity&quot;);<br></td></tr
><tr
id=sl_svn7768_879

><td class="source">      setOpacity(opacityText);<br></td></tr
><tr
id=sl_svn7768_880

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_881

><td class="source"><br></td></tr
><tr
id=sl_svn7768_882

><td class="source">    if (properties.hasAttribute(&quot;stroke&quot;)) {<br></td></tr
><tr
id=sl_svn7768_883

><td class="source">      String strokeText = properties.getString(&quot;stroke&quot;);<br></td></tr
><tr
id=sl_svn7768_884

><td class="source">      setColor(strokeText, false);<br></td></tr
><tr
id=sl_svn7768_885

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_886

><td class="source">    <br></td></tr
><tr
id=sl_svn7768_887

><td class="source">    if (properties.hasAttribute(&quot;stroke-opacity&quot;)) {<br></td></tr
><tr
id=sl_svn7768_888

><td class="source">      String strokeOpacityText = properties.getString(&quot;stroke-opacity&quot;);<br></td></tr
><tr
id=sl_svn7768_889

><td class="source">      setStrokeOpacity(strokeOpacityText);<br></td></tr
><tr
id=sl_svn7768_890

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_891

><td class="source"><br></td></tr
><tr
id=sl_svn7768_892

><td class="source">    if (properties.hasAttribute(&quot;stroke-width&quot;)) {<br></td></tr
><tr
id=sl_svn7768_893

><td class="source">      // if NaN (i.e. if it&#39;s &#39;inherit&#39;) then default back to the inherit setting<br></td></tr
><tr
id=sl_svn7768_894

><td class="source">      String lineweight = properties.getString(&quot;stroke-width&quot;);<br></td></tr
><tr
id=sl_svn7768_895

><td class="source">      setStrokeWeight(lineweight);<br></td></tr
><tr
id=sl_svn7768_896

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_897

><td class="source"><br></td></tr
><tr
id=sl_svn7768_898

><td class="source">    if (properties.hasAttribute(&quot;stroke-linejoin&quot;)) {<br></td></tr
><tr
id=sl_svn7768_899

><td class="source">      String linejoin = properties.getString(&quot;stroke-linejoin&quot;);<br></td></tr
><tr
id=sl_svn7768_900

><td class="source">      setStrokeJoin(linejoin);<br></td></tr
><tr
id=sl_svn7768_901

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_902

><td class="source"><br></td></tr
><tr
id=sl_svn7768_903

><td class="source">    if (properties.hasAttribute(&quot;stroke-linecap&quot;)) {<br></td></tr
><tr
id=sl_svn7768_904

><td class="source">      String linecap = properties.getString(&quot;stroke-linecap&quot;);<br></td></tr
><tr
id=sl_svn7768_905

><td class="source">      setStrokeCap(linecap);<br></td></tr
><tr
id=sl_svn7768_906

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_907

><td class="source"><br></td></tr
><tr
id=sl_svn7768_908

><td class="source">    // fill defaults to black (though stroke defaults to &quot;none&quot;)<br></td></tr
><tr
id=sl_svn7768_909

><td class="source">    // http://www.w3.org/TR/SVG/painting.html#FillProperties<br></td></tr
><tr
id=sl_svn7768_910

><td class="source">    if (properties.hasAttribute(&quot;fill&quot;)) {<br></td></tr
><tr
id=sl_svn7768_911

><td class="source">      String fillText = properties.getString(&quot;fill&quot;);<br></td></tr
><tr
id=sl_svn7768_912

><td class="source">      setColor(fillText, true);<br></td></tr
><tr
id=sl_svn7768_913

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_914

><td class="source"><br></td></tr
><tr
id=sl_svn7768_915

><td class="source">    if (properties.hasAttribute(&quot;fill-opacity&quot;)) {<br></td></tr
><tr
id=sl_svn7768_916

><td class="source">      String fillOpacityText = properties.getString(&quot;fill-opacity&quot;);<br></td></tr
><tr
id=sl_svn7768_917

><td class="source">      setFillOpacity(fillOpacityText);<br></td></tr
><tr
id=sl_svn7768_918

><td class="source">    }    <br></td></tr
><tr
id=sl_svn7768_919

><td class="source">    <br></td></tr
><tr
id=sl_svn7768_920

><td class="source">    if (properties.hasAttribute(&quot;style&quot;)) {<br></td></tr
><tr
id=sl_svn7768_921

><td class="source">      String styleText = properties.getString(&quot;style&quot;);<br></td></tr
><tr
id=sl_svn7768_922

><td class="source">      String[] styleTokens = PApplet.splitTokens(styleText, &quot;;&quot;);<br></td></tr
><tr
id=sl_svn7768_923

><td class="source"><br></td></tr
><tr
id=sl_svn7768_924

><td class="source">      //PApplet.println(styleTokens);<br></td></tr
><tr
id=sl_svn7768_925

><td class="source">      for (int i = 0; i &lt; styleTokens.length; i++) {<br></td></tr
><tr
id=sl_svn7768_926

><td class="source">        String[] tokens = PApplet.splitTokens(styleTokens[i], &quot;:&quot;);<br></td></tr
><tr
id=sl_svn7768_927

><td class="source">        //PApplet.println(tokens);<br></td></tr
><tr
id=sl_svn7768_928

><td class="source"><br></td></tr
><tr
id=sl_svn7768_929

><td class="source">        tokens[0] = PApplet.trim(tokens[0]);<br></td></tr
><tr
id=sl_svn7768_930

><td class="source"><br></td></tr
><tr
id=sl_svn7768_931

><td class="source">        if (tokens[0].equals(&quot;fill&quot;)) {<br></td></tr
><tr
id=sl_svn7768_932

><td class="source">          setColor(tokens[1], true);<br></td></tr
><tr
id=sl_svn7768_933

><td class="source"><br></td></tr
><tr
id=sl_svn7768_934

><td class="source">        } else if(tokens[0].equals(&quot;fill-opacity&quot;)) {<br></td></tr
><tr
id=sl_svn7768_935

><td class="source">          setFillOpacity(tokens[1]);<br></td></tr
><tr
id=sl_svn7768_936

><td class="source"><br></td></tr
><tr
id=sl_svn7768_937

><td class="source">        } else if(tokens[0].equals(&quot;stroke&quot;)) {<br></td></tr
><tr
id=sl_svn7768_938

><td class="source">          setColor(tokens[1], false);<br></td></tr
><tr
id=sl_svn7768_939

><td class="source"><br></td></tr
><tr
id=sl_svn7768_940

><td class="source">        } else if(tokens[0].equals(&quot;stroke-width&quot;)) {<br></td></tr
><tr
id=sl_svn7768_941

><td class="source">          setStrokeWeight(tokens[1]);<br></td></tr
><tr
id=sl_svn7768_942

><td class="source"><br></td></tr
><tr
id=sl_svn7768_943

><td class="source">        } else if(tokens[0].equals(&quot;stroke-linecap&quot;)) {<br></td></tr
><tr
id=sl_svn7768_944

><td class="source">          setStrokeCap(tokens[1]);<br></td></tr
><tr
id=sl_svn7768_945

><td class="source"><br></td></tr
><tr
id=sl_svn7768_946

><td class="source">        } else if(tokens[0].equals(&quot;stroke-linejoin&quot;)) {<br></td></tr
><tr
id=sl_svn7768_947

><td class="source">          setStrokeJoin(tokens[1]);<br></td></tr
><tr
id=sl_svn7768_948

><td class="source"><br></td></tr
><tr
id=sl_svn7768_949

><td class="source">        } else if(tokens[0].equals(&quot;stroke-opacity&quot;)) {<br></td></tr
><tr
id=sl_svn7768_950

><td class="source">          setStrokeOpacity(tokens[1]);<br></td></tr
><tr
id=sl_svn7768_951

><td class="source"><br></td></tr
><tr
id=sl_svn7768_952

><td class="source">        } else if(tokens[0].equals(&quot;opacity&quot;)) {<br></td></tr
><tr
id=sl_svn7768_953

><td class="source">          setOpacity(tokens[1]);<br></td></tr
><tr
id=sl_svn7768_954

><td class="source"><br></td></tr
><tr
id=sl_svn7768_955

><td class="source">        } else {<br></td></tr
><tr
id=sl_svn7768_956

><td class="source">          // Other attributes are not yet implemented<br></td></tr
><tr
id=sl_svn7768_957

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_958

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_959

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_960

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_961

><td class="source"><br></td></tr
><tr
id=sl_svn7768_962

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_963

><td class="source">  void setOpacity(String opacityText) {<br></td></tr
><tr
id=sl_svn7768_964

><td class="source">    opacity = PApplet.parseFloat(opacityText);<br></td></tr
><tr
id=sl_svn7768_965

><td class="source">    strokeColor = ((int) (opacity * 255)) &lt;&lt; 24 | strokeColor &amp; 0xFFFFFF;<br></td></tr
><tr
id=sl_svn7768_966

><td class="source">    fillColor = ((int) (opacity * 255)) &lt;&lt; 24 | fillColor &amp; 0xFFFFFF;<br></td></tr
><tr
id=sl_svn7768_967

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_968

><td class="source"><br></td></tr
><tr
id=sl_svn7768_969

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_970

><td class="source">  void setStrokeWeight(String lineweight) {<br></td></tr
><tr
id=sl_svn7768_971

><td class="source">    strokeWeight = parseUnitSize(lineweight);<br></td></tr
><tr
id=sl_svn7768_972

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_973

><td class="source"><br></td></tr
><tr
id=sl_svn7768_974

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_975

><td class="source">  void setStrokeOpacity(String opacityText) {<br></td></tr
><tr
id=sl_svn7768_976

><td class="source">    strokeOpacity = PApplet.parseFloat(opacityText);<br></td></tr
><tr
id=sl_svn7768_977

><td class="source">    strokeColor = ((int) (strokeOpacity * 255)) &lt;&lt; 24 | strokeColor &amp; 0xFFFFFF;<br></td></tr
><tr
id=sl_svn7768_978

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_979

><td class="source"><br></td></tr
><tr
id=sl_svn7768_980

><td class="source"><br></td></tr
><tr
id=sl_svn7768_981

><td class="source">  void setStrokeJoin(String linejoin) {<br></td></tr
><tr
id=sl_svn7768_982

><td class="source">    if (linejoin.equals(&quot;inherit&quot;)) {<br></td></tr
><tr
id=sl_svn7768_983

><td class="source">      // do nothing, will inherit automatically<br></td></tr
><tr
id=sl_svn7768_984

><td class="source"><br></td></tr
><tr
id=sl_svn7768_985

><td class="source">    } else if (linejoin.equals(&quot;miter&quot;)) {<br></td></tr
><tr
id=sl_svn7768_986

><td class="source">      strokeJoin = PConstants.MITER;<br></td></tr
><tr
id=sl_svn7768_987

><td class="source"><br></td></tr
><tr
id=sl_svn7768_988

><td class="source">    } else if (linejoin.equals(&quot;round&quot;)) {<br></td></tr
><tr
id=sl_svn7768_989

><td class="source">      strokeJoin = PConstants.ROUND;<br></td></tr
><tr
id=sl_svn7768_990

><td class="source"><br></td></tr
><tr
id=sl_svn7768_991

><td class="source">    } else if (linejoin.equals(&quot;bevel&quot;)) {<br></td></tr
><tr
id=sl_svn7768_992

><td class="source">      strokeJoin = PConstants.BEVEL;<br></td></tr
><tr
id=sl_svn7768_993

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_994

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_995

><td class="source"><br></td></tr
><tr
id=sl_svn7768_996

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_997

><td class="source">  void setStrokeCap(String linecap) {<br></td></tr
><tr
id=sl_svn7768_998

><td class="source">    if (linecap.equals(&quot;inherit&quot;)) {<br></td></tr
><tr
id=sl_svn7768_999

><td class="source">      // do nothing, will inherit automatically<br></td></tr
><tr
id=sl_svn7768_1000

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1001

><td class="source">    } else if (linecap.equals(&quot;butt&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1002

><td class="source">      strokeCap = PConstants.SQUARE;<br></td></tr
><tr
id=sl_svn7768_1003

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1004

><td class="source">    } else if (linecap.equals(&quot;round&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1005

><td class="source">      strokeCap = PConstants.ROUND;<br></td></tr
><tr
id=sl_svn7768_1006

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1007

><td class="source">    } else if (linecap.equals(&quot;square&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1008

><td class="source">      strokeCap = PConstants.PROJECT;<br></td></tr
><tr
id=sl_svn7768_1009

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1010

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1011

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_1012

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1013

><td class="source">  void setFillOpacity(String opacityText) {<br></td></tr
><tr
id=sl_svn7768_1014

><td class="source">    fillOpacity = PApplet.parseFloat(opacityText);<br></td></tr
><tr
id=sl_svn7768_1015

><td class="source">    fillColor = ((int) (fillOpacity * 255)) &lt;&lt; 24 | fillColor &amp; 0xFFFFFF;<br></td></tr
><tr
id=sl_svn7768_1016

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1017

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_1018

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1019

><td class="source">  void setColor(String colorText, boolean isFill) {<br></td></tr
><tr
id=sl_svn7768_1020

><td class="source">    int opacityMask = fillColor &amp; 0xFF000000;<br></td></tr
><tr
id=sl_svn7768_1021

><td class="source">    boolean visible = true;<br></td></tr
><tr
id=sl_svn7768_1022

><td class="source">    int color = 0;<br></td></tr
><tr
id=sl_svn7768_1023

><td class="source">    String name = &quot;&quot;;<br></td></tr
><tr
id=sl_svn7768_1024

><td class="source">    Gradient gradient = null;<br></td></tr
><tr
id=sl_svn7768_1025

><td class="source">    Paint paint = null;<br></td></tr
><tr
id=sl_svn7768_1026

><td class="source">    if (colorText.equals(&quot;none&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1027

><td class="source">      visible = false;<br></td></tr
><tr
id=sl_svn7768_1028

><td class="source">    } else if (colorText.equals(&quot;black&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1029

><td class="source">      color = opacityMask;<br></td></tr
><tr
id=sl_svn7768_1030

><td class="source">    } else if (colorText.equals(&quot;white&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1031

><td class="source">      color = opacityMask | 0xFFFFFF;<br></td></tr
><tr
id=sl_svn7768_1032

><td class="source">    } else if (colorText.startsWith(&quot;#&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1033

><td class="source">      if (colorText.length() == 4) {<br></td></tr
><tr
id=sl_svn7768_1034

><td class="source">        // Short form: #ABC, transform to long form #AABBCC<br></td></tr
><tr
id=sl_svn7768_1035

><td class="source">        colorText = colorText.replaceAll(&quot;^#(.)(.)(.)$&quot;, &quot;#$1$1$2$2$3$3&quot;);<br></td></tr
><tr
id=sl_svn7768_1036

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1037

><td class="source">      color = opacityMask |<br></td></tr
><tr
id=sl_svn7768_1038

><td class="source">          (Integer.parseInt(colorText.substring(1), 16)) &amp; 0xFFFFFF;<br></td></tr
><tr
id=sl_svn7768_1039

><td class="source">      //System.out.println(&quot;hex for fill is &quot; + PApplet.hex(fillColor));<br></td></tr
><tr
id=sl_svn7768_1040

><td class="source">    } else if (colorText.startsWith(&quot;rgb&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1041

><td class="source">      color = opacityMask | parseRGB(colorText);<br></td></tr
><tr
id=sl_svn7768_1042

><td class="source">    } else if (colorText.startsWith(&quot;url(#&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1043

><td class="source">      name = colorText.substring(5, colorText.length() - 1);<br></td></tr
><tr
id=sl_svn7768_1044

><td class="source">//      PApplet.println(&quot;looking for &quot; + name);<br></td></tr
><tr
id=sl_svn7768_1045

><td class="source">      Object object = findChild(name);<br></td></tr
><tr
id=sl_svn7768_1046

><td class="source">      //PApplet.println(&quot;found &quot; + fillObject);<br></td></tr
><tr
id=sl_svn7768_1047

><td class="source">      if (object instanceof Gradient) {<br></td></tr
><tr
id=sl_svn7768_1048

><td class="source">        gradient = (Gradient) object;<br></td></tr
><tr
id=sl_svn7768_1049

><td class="source">        paint = calcGradientPaint(gradient); //, opacity);<br></td></tr
><tr
id=sl_svn7768_1050

><td class="source">        //PApplet.println(&quot;got filla &quot; + fillObject);<br></td></tr
><tr
id=sl_svn7768_1051

><td class="source">      } else {<br></td></tr
><tr
id=sl_svn7768_1052

><td class="source">//        visible = false;<br></td></tr
><tr
id=sl_svn7768_1053

><td class="source">        System.err.println(&quot;url &quot; + name + &quot; refers to unexpected data: &quot; + object);<br></td></tr
><tr
id=sl_svn7768_1054

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1055

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1056

><td class="source">    if (isFill) {<br></td></tr
><tr
id=sl_svn7768_1057

><td class="source">      fill = visible;<br></td></tr
><tr
id=sl_svn7768_1058

><td class="source">      fillColor = color;<br></td></tr
><tr
id=sl_svn7768_1059

><td class="source">      fillName = name;<br></td></tr
><tr
id=sl_svn7768_1060

><td class="source">      fillGradient = gradient;<br></td></tr
><tr
id=sl_svn7768_1061

><td class="source">      fillGradientPaint = paint;<br></td></tr
><tr
id=sl_svn7768_1062

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn7768_1063

><td class="source">      stroke = visible;<br></td></tr
><tr
id=sl_svn7768_1064

><td class="source">      strokeColor = color;<br></td></tr
><tr
id=sl_svn7768_1065

><td class="source">      strokeName = name;<br></td></tr
><tr
id=sl_svn7768_1066

><td class="source">      strokeGradient = gradient;<br></td></tr
><tr
id=sl_svn7768_1067

><td class="source">      strokeGradientPaint = paint;<br></td></tr
><tr
id=sl_svn7768_1068

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1069

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1070

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1071

><td class="source">  <br></td></tr
><tr
id=sl_svn7768_1072

><td class="source">  static protected int parseRGB(String what) {<br></td></tr
><tr
id=sl_svn7768_1073

><td class="source">    int leftParen = what.indexOf(&#39;(&#39;) + 1;<br></td></tr
><tr
id=sl_svn7768_1074

><td class="source">    int rightParen = what.indexOf(&#39;)&#39;);<br></td></tr
><tr
id=sl_svn7768_1075

><td class="source">    String sub = what.substring(leftParen, rightParen);<br></td></tr
><tr
id=sl_svn7768_1076

><td class="source">    int[] values = PApplet.parseInt(PApplet.splitTokens(sub, &quot;, &quot;));<br></td></tr
><tr
id=sl_svn7768_1077

><td class="source">    return (values[0] &lt;&lt; 16) | (values[1] &lt;&lt; 8) | (values[2]);<br></td></tr
><tr
id=sl_svn7768_1078

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1079

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1080

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1081

><td class="source">  static protected HashMap&lt;String, String&gt; parseStyleAttributes(String style) {<br></td></tr
><tr
id=sl_svn7768_1082

><td class="source">    HashMap&lt;String, String&gt; table = new HashMap&lt;String, String&gt;();<br></td></tr
><tr
id=sl_svn7768_1083

><td class="source">    String[] pieces = style.split(&quot;;&quot;);<br></td></tr
><tr
id=sl_svn7768_1084

><td class="source">    for (int i = 0; i &lt; pieces.length; i++) {<br></td></tr
><tr
id=sl_svn7768_1085

><td class="source">      String[] parts = pieces[i].split(&quot;:&quot;);<br></td></tr
><tr
id=sl_svn7768_1086

><td class="source">      table.put(parts[0], parts[1]);<br></td></tr
><tr
id=sl_svn7768_1087

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1088

><td class="source">    return table;<br></td></tr
><tr
id=sl_svn7768_1089

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1090

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1091

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1092

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_1093

><td class="source">   * Used in place of element.getFloatAttribute(a) because we can <br></td></tr
><tr
id=sl_svn7768_1094

><td class="source">   * have a unit suffix (length or coordinate).<br></td></tr
><tr
id=sl_svn7768_1095

><td class="source">   * @param element what to parse<br></td></tr
><tr
id=sl_svn7768_1096

><td class="source">   * @param attribute name of the attribute to get<br></td></tr
><tr
id=sl_svn7768_1097

><td class="source">   * @return unit-parsed version of the data<br></td></tr
><tr
id=sl_svn7768_1098

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_1099

><td class="source">  static protected float getFloatWithUnit(XMLElement element, String attribute) {<br></td></tr
><tr
id=sl_svn7768_1100

><td class="source">    String val = element.getString(attribute);<br></td></tr
><tr
id=sl_svn7768_1101

><td class="source">    return (val == null) ? 0 : parseUnitSize(val);<br></td></tr
><tr
id=sl_svn7768_1102

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1103

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1104

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1105

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_1106

><td class="source">   * Parse a size that may have a suffix for its units.<br></td></tr
><tr
id=sl_svn7768_1107

><td class="source">   * Ignoring cases where this could also be a percentage.<br></td></tr
><tr
id=sl_svn7768_1108

><td class="source">   * The &lt;A HREF=&quot;http://www.w3.org/TR/SVG/coords.html#Units&quot;&gt;units&lt;/A&gt; spec:<br></td></tr
><tr
id=sl_svn7768_1109

><td class="source">   * &lt;UL&gt;<br></td></tr
><tr
id=sl_svn7768_1110

><td class="source">   * &lt;LI&gt;&quot;1pt&quot; equals &quot;1.25px&quot; (and therefore 1.25 user units)<br></td></tr
><tr
id=sl_svn7768_1111

><td class="source">   * &lt;LI&gt;&quot;1pc&quot; equals &quot;15px&quot; (and therefore 15 user units)<br></td></tr
><tr
id=sl_svn7768_1112

><td class="source">   * &lt;LI&gt;&quot;1mm&quot; would be &quot;3.543307px&quot; (3.543307 user units)<br></td></tr
><tr
id=sl_svn7768_1113

><td class="source">   * &lt;LI&gt;&quot;1cm&quot; equals &quot;35.43307px&quot; (and therefore 35.43307 user units)<br></td></tr
><tr
id=sl_svn7768_1114

><td class="source">   * &lt;LI&gt;&quot;1in&quot; equals &quot;90px&quot; (and therefore 90 user units)<br></td></tr
><tr
id=sl_svn7768_1115

><td class="source">   * &lt;/UL&gt;<br></td></tr
><tr
id=sl_svn7768_1116

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_1117

><td class="source">  static protected float parseUnitSize(String text) {<br></td></tr
><tr
id=sl_svn7768_1118

><td class="source">    int len = text.length() - 2;<br></td></tr
><tr
id=sl_svn7768_1119

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1120

><td class="source">    if (text.endsWith(&quot;pt&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1121

><td class="source">      return PApplet.parseFloat(text.substring(0, len)) * 1.25f;<br></td></tr
><tr
id=sl_svn7768_1122

><td class="source">    } else if (text.endsWith(&quot;pc&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1123

><td class="source">      return PApplet.parseFloat(text.substring(0, len)) * 15;<br></td></tr
><tr
id=sl_svn7768_1124

><td class="source">    } else if (text.endsWith(&quot;mm&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1125

><td class="source">      return PApplet.parseFloat(text.substring(0, len)) * 3.543307f;<br></td></tr
><tr
id=sl_svn7768_1126

><td class="source">    } else if (text.endsWith(&quot;cm&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1127

><td class="source">      return PApplet.parseFloat(text.substring(0, len)) * 35.43307f;<br></td></tr
><tr
id=sl_svn7768_1128

><td class="source">    } else if (text.endsWith(&quot;in&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1129

><td class="source">      return PApplet.parseFloat(text.substring(0, len)) * 90;<br></td></tr
><tr
id=sl_svn7768_1130

><td class="source">    } else if (text.endsWith(&quot;px&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1131

><td class="source">      return PApplet.parseFloat(text.substring(0, len));<br></td></tr
><tr
id=sl_svn7768_1132

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn7768_1133

><td class="source">      return PApplet.parseFloat(text);<br></td></tr
><tr
id=sl_svn7768_1134

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1135

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1136

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1137

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1138

><td class="source">  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .<br></td></tr
><tr
id=sl_svn7768_1139

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1140

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1141

><td class="source">  static class Gradient extends PShapeSVG {<br></td></tr
><tr
id=sl_svn7768_1142

><td class="source">    AffineTransform transform;<br></td></tr
><tr
id=sl_svn7768_1143

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1144

><td class="source">    float[] offset;<br></td></tr
><tr
id=sl_svn7768_1145

><td class="source">    int[] color;<br></td></tr
><tr
id=sl_svn7768_1146

><td class="source">    int count;<br></td></tr
><tr
id=sl_svn7768_1147

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1148

><td class="source">    public Gradient(PShapeSVG parent, XMLElement properties) {<br></td></tr
><tr
id=sl_svn7768_1149

><td class="source">      super(parent, properties);<br></td></tr
><tr
id=sl_svn7768_1150

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1151

><td class="source">      XMLElement elements[] = properties.getChildren();<br></td></tr
><tr
id=sl_svn7768_1152

><td class="source">      offset = new float[elements.length];<br></td></tr
><tr
id=sl_svn7768_1153

><td class="source">      color = new int[elements.length];<br></td></tr
><tr
id=sl_svn7768_1154

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1155

><td class="source">      // &lt;stop  offset=&quot;0&quot; style=&quot;stop-color:#967348&quot;/&gt;<br></td></tr
><tr
id=sl_svn7768_1156

><td class="source">      for (int i = 0; i &lt; elements.length; i++) {<br></td></tr
><tr
id=sl_svn7768_1157

><td class="source">        XMLElement elem = elements[i];<br></td></tr
><tr
id=sl_svn7768_1158

><td class="source">        String name = elem.getName();<br></td></tr
><tr
id=sl_svn7768_1159

><td class="source">        if (name.equals(&quot;stop&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1160

><td class="source">          String offsetAttr = elem.getString(&quot;offset&quot;);<br></td></tr
><tr
id=sl_svn7768_1161

><td class="source">          float div = 1.0f;<br></td></tr
><tr
id=sl_svn7768_1162

><td class="source">          if (offsetAttr.endsWith(&quot;%&quot;)) {<br></td></tr
><tr
id=sl_svn7768_1163

><td class="source">            div = 100.0f;<br></td></tr
><tr
id=sl_svn7768_1164

><td class="source">            offsetAttr = offsetAttr.substring(0, offsetAttr.length() - 1);<br></td></tr
><tr
id=sl_svn7768_1165

><td class="source">          }<br></td></tr
><tr
id=sl_svn7768_1166

><td class="source">          offset[count] = PApplet.parseFloat(offsetAttr) / div;<br></td></tr
><tr
id=sl_svn7768_1167

><td class="source">          String style = elem.getString(&quot;style&quot;);<br></td></tr
><tr
id=sl_svn7768_1168

><td class="source">          HashMap&lt;String, String&gt; styles = parseStyleAttributes(style);<br></td></tr
><tr
id=sl_svn7768_1169

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1170

><td class="source">          String colorStr = styles.get(&quot;stop-color&quot;);<br></td></tr
><tr
id=sl_svn7768_1171

><td class="source">          if (colorStr == null) colorStr = &quot;#000000&quot;;<br></td></tr
><tr
id=sl_svn7768_1172

><td class="source">          String opacityStr = styles.get(&quot;stop-opacity&quot;);<br></td></tr
><tr
id=sl_svn7768_1173

><td class="source">          if (opacityStr == null) opacityStr = &quot;1&quot;;<br></td></tr
><tr
id=sl_svn7768_1174

><td class="source">          int tupacity = (int) (PApplet.parseFloat(opacityStr) * 255);<br></td></tr
><tr
id=sl_svn7768_1175

><td class="source">          color[count] = (tupacity &lt;&lt; 24) |<br></td></tr
><tr
id=sl_svn7768_1176

><td class="source">            Integer.parseInt(colorStr.substring(1), 16);<br></td></tr
><tr
id=sl_svn7768_1177

><td class="source">          count++;<br></td></tr
><tr
id=sl_svn7768_1178

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_1179

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1180

><td class="source">      offset = PApplet.subset(offset, 0, count);<br></td></tr
><tr
id=sl_svn7768_1181

><td class="source">      color = PApplet.subset(color, 0, count);<br></td></tr
><tr
id=sl_svn7768_1182

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1183

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1184

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1185

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1186

><td class="source">  class LinearGradient extends Gradient {<br></td></tr
><tr
id=sl_svn7768_1187

><td class="source">    float x1, y1, x2, y2;<br></td></tr
><tr
id=sl_svn7768_1188

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1189

><td class="source">    public LinearGradient(PShapeSVG parent, XMLElement properties) {<br></td></tr
><tr
id=sl_svn7768_1190

><td class="source">      super(parent, properties);<br></td></tr
><tr
id=sl_svn7768_1191

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1192

><td class="source">      this.x1 = getFloatWithUnit(properties, &quot;x1&quot;);<br></td></tr
><tr
id=sl_svn7768_1193

><td class="source">      this.y1 = getFloatWithUnit(properties, &quot;y1&quot;);<br></td></tr
><tr
id=sl_svn7768_1194

><td class="source">      this.x2 = getFloatWithUnit(properties, &quot;x2&quot;);<br></td></tr
><tr
id=sl_svn7768_1195

><td class="source">      this.y2 = getFloatWithUnit(properties, &quot;y2&quot;);<br></td></tr
><tr
id=sl_svn7768_1196

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1197

><td class="source">      String transformStr =<br></td></tr
><tr
id=sl_svn7768_1198

><td class="source">        properties.getString(&quot;gradientTransform&quot;);<br></td></tr
><tr
id=sl_svn7768_1199

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1200

><td class="source">      if (transformStr != null) {<br></td></tr
><tr
id=sl_svn7768_1201

><td class="source">        float t[] = parseMatrix(transformStr).get(null);<br></td></tr
><tr
id=sl_svn7768_1202

><td class="source">        this.transform = new AffineTransform(t[0], t[3], t[1], t[4], t[2], t[5]);<br></td></tr
><tr
id=sl_svn7768_1203

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1204

><td class="source">        Point2D t1 = transform.transform(new Point2D.Float(x1, y1), null);<br></td></tr
><tr
id=sl_svn7768_1205

><td class="source">        Point2D t2 = transform.transform(new Point2D.Float(x2, y2), null);<br></td></tr
><tr
id=sl_svn7768_1206

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1207

><td class="source">        this.x1 = (float) t1.getX();<br></td></tr
><tr
id=sl_svn7768_1208

><td class="source">        this.y1 = (float) t1.getY();<br></td></tr
><tr
id=sl_svn7768_1209

><td class="source">        this.x2 = (float) t2.getX();<br></td></tr
><tr
id=sl_svn7768_1210

><td class="source">        this.y2 = (float) t2.getY();<br></td></tr
><tr
id=sl_svn7768_1211

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1212

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1213

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1214

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1215

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1216

><td class="source">  class RadialGradient extends Gradient {<br></td></tr
><tr
id=sl_svn7768_1217

><td class="source">    float cx, cy, r;<br></td></tr
><tr
id=sl_svn7768_1218

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1219

><td class="source">    public RadialGradient(PShapeSVG parent, XMLElement properties) {<br></td></tr
><tr
id=sl_svn7768_1220

><td class="source">      super(parent, properties);<br></td></tr
><tr
id=sl_svn7768_1221

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1222

><td class="source">      this.cx = getFloatWithUnit(properties, &quot;cx&quot;);<br></td></tr
><tr
id=sl_svn7768_1223

><td class="source">      this.cy = getFloatWithUnit(properties, &quot;cy&quot;);<br></td></tr
><tr
id=sl_svn7768_1224

><td class="source">      this.r  = getFloatWithUnit(properties, &quot;r&quot;);<br></td></tr
><tr
id=sl_svn7768_1225

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1226

><td class="source">      String transformStr =<br></td></tr
><tr
id=sl_svn7768_1227

><td class="source">        properties.getString(&quot;gradientTransform&quot;);<br></td></tr
><tr
id=sl_svn7768_1228

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1229

><td class="source">      if (transformStr != null) {<br></td></tr
><tr
id=sl_svn7768_1230

><td class="source">        float t[] = parseMatrix(transformStr).get(null);<br></td></tr
><tr
id=sl_svn7768_1231

><td class="source">        this.transform = new AffineTransform(t[0], t[3], t[1], t[4], t[2], t[5]);<br></td></tr
><tr
id=sl_svn7768_1232

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1233

><td class="source">        Point2D t1 = transform.transform(new Point2D.Float(cx, cy), null);<br></td></tr
><tr
id=sl_svn7768_1234

><td class="source">        Point2D t2 = transform.transform(new Point2D.Float(cx + r, cy), null);<br></td></tr
><tr
id=sl_svn7768_1235

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1236

><td class="source">        this.cx = (float) t1.getX();<br></td></tr
><tr
id=sl_svn7768_1237

><td class="source">        this.cy = (float) t1.getY();<br></td></tr
><tr
id=sl_svn7768_1238

><td class="source">        this.r = (float) (t2.getX() - t1.getX());<br></td></tr
><tr
id=sl_svn7768_1239

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1240

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1241

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1242

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1243

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1244

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1245

><td class="source">  class LinearGradientPaint implements Paint {<br></td></tr
><tr
id=sl_svn7768_1246

><td class="source">    float x1, y1, x2, y2;<br></td></tr
><tr
id=sl_svn7768_1247

><td class="source">    float[] offset;<br></td></tr
><tr
id=sl_svn7768_1248

><td class="source">    int[] color;<br></td></tr
><tr
id=sl_svn7768_1249

><td class="source">    int count;<br></td></tr
><tr
id=sl_svn7768_1250

><td class="source">    float opacity;<br></td></tr
><tr
id=sl_svn7768_1251

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1252

><td class="source">    public LinearGradientPaint(float x1, float y1, float x2, float y2,<br></td></tr
><tr
id=sl_svn7768_1253

><td class="source">                               float[] offset, int[] color, int count,<br></td></tr
><tr
id=sl_svn7768_1254

><td class="source">                               float opacity) {<br></td></tr
><tr
id=sl_svn7768_1255

><td class="source">      this.x1 = x1;<br></td></tr
><tr
id=sl_svn7768_1256

><td class="source">      this.y1 = y1;<br></td></tr
><tr
id=sl_svn7768_1257

><td class="source">      this.x2 = x2;<br></td></tr
><tr
id=sl_svn7768_1258

><td class="source">      this.y2 = y2;<br></td></tr
><tr
id=sl_svn7768_1259

><td class="source">      this.offset = offset;<br></td></tr
><tr
id=sl_svn7768_1260

><td class="source">      this.color = color;<br></td></tr
><tr
id=sl_svn7768_1261

><td class="source">      this.count = count;<br></td></tr
><tr
id=sl_svn7768_1262

><td class="source">      this.opacity = opacity;<br></td></tr
><tr
id=sl_svn7768_1263

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1264

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1265

><td class="source">    public PaintContext createContext(ColorModel cm,<br></td></tr
><tr
id=sl_svn7768_1266

><td class="source">                                      Rectangle deviceBounds, Rectangle2D userBounds,<br></td></tr
><tr
id=sl_svn7768_1267

><td class="source">                                      AffineTransform xform, RenderingHints hints) {<br></td></tr
><tr
id=sl_svn7768_1268

><td class="source">      Point2D t1 = xform.transform(new Point2D.Float(x1, y1), null);<br></td></tr
><tr
id=sl_svn7768_1269

><td class="source">      Point2D t2 = xform.transform(new Point2D.Float(x2, y2), null);<br></td></tr
><tr
id=sl_svn7768_1270

><td class="source">      return new LinearGradientContext((float) t1.getX(), (float) t1.getY(),<br></td></tr
><tr
id=sl_svn7768_1271

><td class="source">                                       (float) t2.getX(), (float) t2.getY());<br></td></tr
><tr
id=sl_svn7768_1272

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1273

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1274

><td class="source">    public int getTransparency() {<br></td></tr
><tr
id=sl_svn7768_1275

><td class="source">      return TRANSLUCENT;  // why not.. rather than checking each color<br></td></tr
><tr
id=sl_svn7768_1276

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1277

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1278

><td class="source">    public class LinearGradientContext implements PaintContext {<br></td></tr
><tr
id=sl_svn7768_1279

><td class="source">      int ACCURACY = 2;<br></td></tr
><tr
id=sl_svn7768_1280

><td class="source">      float tx1, ty1, tx2, ty2;<br></td></tr
><tr
id=sl_svn7768_1281

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1282

><td class="source">      public LinearGradientContext(float tx1, float ty1, float tx2, float ty2) {<br></td></tr
><tr
id=sl_svn7768_1283

><td class="source">        this.tx1 = tx1;<br></td></tr
><tr
id=sl_svn7768_1284

><td class="source">        this.ty1 = ty1;<br></td></tr
><tr
id=sl_svn7768_1285

><td class="source">        this.tx2 = tx2;<br></td></tr
><tr
id=sl_svn7768_1286

><td class="source">        this.ty2 = ty2;<br></td></tr
><tr
id=sl_svn7768_1287

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1288

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1289

><td class="source">      public void dispose() { }<br></td></tr
><tr
id=sl_svn7768_1290

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1291

><td class="source">      public ColorModel getColorModel() { return ColorModel.getRGBdefault(); }<br></td></tr
><tr
id=sl_svn7768_1292

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1293

><td class="source">      public Raster getRaster(int x, int y, int w, int h) {<br></td></tr
><tr
id=sl_svn7768_1294

><td class="source">        WritableRaster raster =<br></td></tr
><tr
id=sl_svn7768_1295

><td class="source">          getColorModel().createCompatibleWritableRaster(w, h);<br></td></tr
><tr
id=sl_svn7768_1296

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1297

><td class="source">        int[] data = new int[w * h * 4];<br></td></tr
><tr
id=sl_svn7768_1298

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1299

><td class="source">        // make normalized version of base vector<br></td></tr
><tr
id=sl_svn7768_1300

><td class="source">        float nx = tx2 - tx1;<br></td></tr
><tr
id=sl_svn7768_1301

><td class="source">        float ny = ty2 - ty1;<br></td></tr
><tr
id=sl_svn7768_1302

><td class="source">        float len = (float) Math.sqrt(nx*nx + ny*ny);<br></td></tr
><tr
id=sl_svn7768_1303

><td class="source">        if (len != 0) {<br></td></tr
><tr
id=sl_svn7768_1304

><td class="source">          nx /= len;<br></td></tr
><tr
id=sl_svn7768_1305

><td class="source">          ny /= len;<br></td></tr
><tr
id=sl_svn7768_1306

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_1307

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1308

><td class="source">        int span = (int) PApplet.dist(tx1, ty1, tx2, ty2) * ACCURACY;<br></td></tr
><tr
id=sl_svn7768_1309

><td class="source">        if (span &lt;= 0) {<br></td></tr
><tr
id=sl_svn7768_1310

><td class="source">          //System.err.println(&quot;span is too small&quot;);<br></td></tr
><tr
id=sl_svn7768_1311

><td class="source">          // annoying edge case where the gradient isn&#39;t legit<br></td></tr
><tr
id=sl_svn7768_1312

><td class="source">          int index = 0;<br></td></tr
><tr
id=sl_svn7768_1313

><td class="source">          for (int j = 0; j &lt; h; j++) {<br></td></tr
><tr
id=sl_svn7768_1314

><td class="source">            for (int i = 0; i &lt; w; i++) {<br></td></tr
><tr
id=sl_svn7768_1315

><td class="source">              data[index++] = 0;<br></td></tr
><tr
id=sl_svn7768_1316

><td class="source">              data[index++] = 0;<br></td></tr
><tr
id=sl_svn7768_1317

><td class="source">              data[index++] = 0;<br></td></tr
><tr
id=sl_svn7768_1318

><td class="source">              data[index++] = 255;<br></td></tr
><tr
id=sl_svn7768_1319

><td class="source">            }<br></td></tr
><tr
id=sl_svn7768_1320

><td class="source">          }<br></td></tr
><tr
id=sl_svn7768_1321

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1322

><td class="source">        } else {<br></td></tr
><tr
id=sl_svn7768_1323

><td class="source">          int[][] interp = new int[span][4];<br></td></tr
><tr
id=sl_svn7768_1324

><td class="source">          int prev = 0;<br></td></tr
><tr
id=sl_svn7768_1325

><td class="source">          for (int i = 1; i &lt; count; i++) {<br></td></tr
><tr
id=sl_svn7768_1326

><td class="source">            int c0 = color[i-1];<br></td></tr
><tr
id=sl_svn7768_1327

><td class="source">            int c1 = color[i];<br></td></tr
><tr
id=sl_svn7768_1328

><td class="source">            int last = (int) (offset[i] * (span-1));<br></td></tr
><tr
id=sl_svn7768_1329

><td class="source">            //System.out.println(&quot;last is &quot; + last);<br></td></tr
><tr
id=sl_svn7768_1330

><td class="source">            for (int j = prev; j &lt;= last; j++) {<br></td></tr
><tr
id=sl_svn7768_1331

><td class="source">              float btwn = PApplet.norm(j, prev, last);<br></td></tr
><tr
id=sl_svn7768_1332

><td class="source">              interp[j][0] = (int) PApplet.lerp((c0 &gt;&gt; 16) &amp; 0xff, (c1 &gt;&gt; 16) &amp; 0xff, btwn);<br></td></tr
><tr
id=sl_svn7768_1333

><td class="source">              interp[j][1] = (int) PApplet.lerp((c0 &gt;&gt; 8) &amp; 0xff, (c1 &gt;&gt; 8) &amp; 0xff, btwn);<br></td></tr
><tr
id=sl_svn7768_1334

><td class="source">              interp[j][2] = (int) PApplet.lerp(c0 &amp; 0xff, c1 &amp; 0xff, btwn);<br></td></tr
><tr
id=sl_svn7768_1335

><td class="source">              interp[j][3] = (int) (PApplet.lerp((c0 &gt;&gt; 24) &amp; 0xff, (c1 &gt;&gt; 24) &amp; 0xff, btwn) * opacity);<br></td></tr
><tr
id=sl_svn7768_1336

><td class="source">              //System.out.println(j + &quot; &quot; + interp[j][0] + &quot; &quot; + interp[j][1] + &quot; &quot; + interp[j][2]);<br></td></tr
><tr
id=sl_svn7768_1337

><td class="source">            }<br></td></tr
><tr
id=sl_svn7768_1338

><td class="source">            prev = last;<br></td></tr
><tr
id=sl_svn7768_1339

><td class="source">          }<br></td></tr
><tr
id=sl_svn7768_1340

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1341

><td class="source">          int index = 0;<br></td></tr
><tr
id=sl_svn7768_1342

><td class="source">          for (int j = 0; j &lt; h; j++) {<br></td></tr
><tr
id=sl_svn7768_1343

><td class="source">            for (int i = 0; i &lt; w; i++) {<br></td></tr
><tr
id=sl_svn7768_1344

><td class="source">              //float distance = 0; //PApplet.dist(cx, cy, x + i, y + j);<br></td></tr
><tr
id=sl_svn7768_1345

><td class="source">              //int which = PApplet.min((int) (distance * ACCURACY), interp.length-1);<br></td></tr
><tr
id=sl_svn7768_1346

><td class="source">              float px = (x + i) - tx1;<br></td></tr
><tr
id=sl_svn7768_1347

><td class="source">              float py = (y + j) - ty1;<br></td></tr
><tr
id=sl_svn7768_1348

><td class="source">              // distance up the line is the dot product of the normalized<br></td></tr
><tr
id=sl_svn7768_1349

><td class="source">              // vector of the gradient start/stop by the point being tested<br></td></tr
><tr
id=sl_svn7768_1350

><td class="source">              int which = (int) ((px*nx + py*ny) * ACCURACY);<br></td></tr
><tr
id=sl_svn7768_1351

><td class="source">              if (which &lt; 0) which = 0;<br></td></tr
><tr
id=sl_svn7768_1352

><td class="source">              if (which &gt; interp.length-1) which = interp.length-1;<br></td></tr
><tr
id=sl_svn7768_1353

><td class="source">              //if (which &gt; 138) System.out.println(&quot;grabbing &quot; + which);<br></td></tr
><tr
id=sl_svn7768_1354

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1355

><td class="source">              data[index++] = interp[which][0];<br></td></tr
><tr
id=sl_svn7768_1356

><td class="source">              data[index++] = interp[which][1];<br></td></tr
><tr
id=sl_svn7768_1357

><td class="source">              data[index++] = interp[which][2];<br></td></tr
><tr
id=sl_svn7768_1358

><td class="source">              data[index++] = interp[which][3];<br></td></tr
><tr
id=sl_svn7768_1359

><td class="source">            }<br></td></tr
><tr
id=sl_svn7768_1360

><td class="source">          }<br></td></tr
><tr
id=sl_svn7768_1361

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_1362

><td class="source">        raster.setPixels(0, 0, w, h, data);<br></td></tr
><tr
id=sl_svn7768_1363

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1364

><td class="source">        return raster;<br></td></tr
><tr
id=sl_svn7768_1365

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1366

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1367

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1368

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1369

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1370

><td class="source">  class RadialGradientPaint implements Paint {<br></td></tr
><tr
id=sl_svn7768_1371

><td class="source">    float cx, cy, radius;<br></td></tr
><tr
id=sl_svn7768_1372

><td class="source">    float[] offset;<br></td></tr
><tr
id=sl_svn7768_1373

><td class="source">    int[] color;<br></td></tr
><tr
id=sl_svn7768_1374

><td class="source">    int count;<br></td></tr
><tr
id=sl_svn7768_1375

><td class="source">    float opacity;<br></td></tr
><tr
id=sl_svn7768_1376

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1377

><td class="source">    public RadialGradientPaint(float cx, float cy, float radius,<br></td></tr
><tr
id=sl_svn7768_1378

><td class="source">                               float[] offset, int[] color, int count,<br></td></tr
><tr
id=sl_svn7768_1379

><td class="source">                               float opacity) {<br></td></tr
><tr
id=sl_svn7768_1380

><td class="source">      this.cx = cx;<br></td></tr
><tr
id=sl_svn7768_1381

><td class="source">      this.cy = cy;<br></td></tr
><tr
id=sl_svn7768_1382

><td class="source">      this.radius = radius;<br></td></tr
><tr
id=sl_svn7768_1383

><td class="source">      this.offset = offset;<br></td></tr
><tr
id=sl_svn7768_1384

><td class="source">      this.color = color;<br></td></tr
><tr
id=sl_svn7768_1385

><td class="source">      this.count = count;<br></td></tr
><tr
id=sl_svn7768_1386

><td class="source">      this.opacity = opacity;<br></td></tr
><tr
id=sl_svn7768_1387

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1388

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1389

><td class="source">    public PaintContext createContext(ColorModel cm,<br></td></tr
><tr
id=sl_svn7768_1390

><td class="source">                                      Rectangle deviceBounds, Rectangle2D userBounds,<br></td></tr
><tr
id=sl_svn7768_1391

><td class="source">                                      AffineTransform xform, RenderingHints hints) {<br></td></tr
><tr
id=sl_svn7768_1392

><td class="source">      return new RadialGradientContext();<br></td></tr
><tr
id=sl_svn7768_1393

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1394

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1395

><td class="source">    public int getTransparency() {<br></td></tr
><tr
id=sl_svn7768_1396

><td class="source">      return TRANSLUCENT;<br></td></tr
><tr
id=sl_svn7768_1397

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1398

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1399

><td class="source">    public class RadialGradientContext implements PaintContext {<br></td></tr
><tr
id=sl_svn7768_1400

><td class="source">      int ACCURACY = 5;<br></td></tr
><tr
id=sl_svn7768_1401

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1402

><td class="source">      public void dispose() {}<br></td></tr
><tr
id=sl_svn7768_1403

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1404

><td class="source">      public ColorModel getColorModel() { return ColorModel.getRGBdefault(); }<br></td></tr
><tr
id=sl_svn7768_1405

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1406

><td class="source">      public Raster getRaster(int x, int y, int w, int h) {<br></td></tr
><tr
id=sl_svn7768_1407

><td class="source">        WritableRaster raster =<br></td></tr
><tr
id=sl_svn7768_1408

><td class="source">          getColorModel().createCompatibleWritableRaster(w, h);<br></td></tr
><tr
id=sl_svn7768_1409

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1410

><td class="source">        int span = (int) radius * ACCURACY;<br></td></tr
><tr
id=sl_svn7768_1411

><td class="source">        int[][] interp = new int[span][4];<br></td></tr
><tr
id=sl_svn7768_1412

><td class="source">        int prev = 0;<br></td></tr
><tr
id=sl_svn7768_1413

><td class="source">        for (int i = 1; i &lt; count; i++) {<br></td></tr
><tr
id=sl_svn7768_1414

><td class="source">          int c0 = color[i-1];<br></td></tr
><tr
id=sl_svn7768_1415

><td class="source">          int c1 = color[i];<br></td></tr
><tr
id=sl_svn7768_1416

><td class="source">          int last = (int) (offset[i] * (span - 1));<br></td></tr
><tr
id=sl_svn7768_1417

><td class="source">          for (int j = prev; j &lt;= last; j++) {<br></td></tr
><tr
id=sl_svn7768_1418

><td class="source">            float btwn = PApplet.norm(j, prev, last);<br></td></tr
><tr
id=sl_svn7768_1419

><td class="source">            interp[j][0] = (int) PApplet.lerp((c0 &gt;&gt; 16) &amp; 0xff, (c1 &gt;&gt; 16) &amp; 0xff, btwn);<br></td></tr
><tr
id=sl_svn7768_1420

><td class="source">            interp[j][1] = (int) PApplet.lerp((c0 &gt;&gt; 8) &amp; 0xff, (c1 &gt;&gt; 8) &amp; 0xff, btwn);<br></td></tr
><tr
id=sl_svn7768_1421

><td class="source">            interp[j][2] = (int) PApplet.lerp(c0 &amp; 0xff, c1 &amp; 0xff, btwn);<br></td></tr
><tr
id=sl_svn7768_1422

><td class="source">            interp[j][3] = (int) (PApplet.lerp((c0 &gt;&gt; 24) &amp; 0xff, (c1 &gt;&gt; 24) &amp; 0xff, btwn) * opacity);<br></td></tr
><tr
id=sl_svn7768_1423

><td class="source">          }<br></td></tr
><tr
id=sl_svn7768_1424

><td class="source">          prev = last;<br></td></tr
><tr
id=sl_svn7768_1425

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_1426

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1427

><td class="source">        int[] data = new int[w * h * 4];<br></td></tr
><tr
id=sl_svn7768_1428

><td class="source">        int index = 0;<br></td></tr
><tr
id=sl_svn7768_1429

><td class="source">        for (int j = 0; j &lt; h; j++) {<br></td></tr
><tr
id=sl_svn7768_1430

><td class="source">          for (int i = 0; i &lt; w; i++) {<br></td></tr
><tr
id=sl_svn7768_1431

><td class="source">            float distance = PApplet.dist(cx, cy, x + i, y + j);<br></td></tr
><tr
id=sl_svn7768_1432

><td class="source">            int which = PApplet.min((int) (distance * ACCURACY), interp.length-1);<br></td></tr
><tr
id=sl_svn7768_1433

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1434

><td class="source">            data[index++] = interp[which][0];<br></td></tr
><tr
id=sl_svn7768_1435

><td class="source">            data[index++] = interp[which][1];<br></td></tr
><tr
id=sl_svn7768_1436

><td class="source">            data[index++] = interp[which][2];<br></td></tr
><tr
id=sl_svn7768_1437

><td class="source">            data[index++] = interp[which][3];<br></td></tr
><tr
id=sl_svn7768_1438

><td class="source">          }<br></td></tr
><tr
id=sl_svn7768_1439

><td class="source">        }<br></td></tr
><tr
id=sl_svn7768_1440

><td class="source">        raster.setPixels(0, 0, w, h, data);<br></td></tr
><tr
id=sl_svn7768_1441

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1442

><td class="source">        return raster;<br></td></tr
><tr
id=sl_svn7768_1443

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1444

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1445

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1446

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1447

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1448

><td class="source">  protected Paint calcGradientPaint(Gradient gradient) {<br></td></tr
><tr
id=sl_svn7768_1449

><td class="source">    if (gradient instanceof LinearGradient) {<br></td></tr
><tr
id=sl_svn7768_1450

><td class="source">      LinearGradient grad = (LinearGradient) gradient;<br></td></tr
><tr
id=sl_svn7768_1451

><td class="source">      return new LinearGradientPaint(grad.x1, grad.y1, grad.x2, grad.y2,<br></td></tr
><tr
id=sl_svn7768_1452

><td class="source">                                     grad.offset, grad.color, grad.count,<br></td></tr
><tr
id=sl_svn7768_1453

><td class="source">                                     opacity);<br></td></tr
><tr
id=sl_svn7768_1454

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1455

><td class="source">    } else if (gradient instanceof RadialGradient) {<br></td></tr
><tr
id=sl_svn7768_1456

><td class="source">      RadialGradient grad = (RadialGradient) gradient;<br></td></tr
><tr
id=sl_svn7768_1457

><td class="source">      return new RadialGradientPaint(grad.cx, grad.cy, grad.r,<br></td></tr
><tr
id=sl_svn7768_1458

><td class="source">                                     grad.offset, grad.color, grad.count,<br></td></tr
><tr
id=sl_svn7768_1459

><td class="source">                                     opacity);<br></td></tr
><tr
id=sl_svn7768_1460

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1461

><td class="source">    return null;<br></td></tr
><tr
id=sl_svn7768_1462

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1463

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1464

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1465

><td class="source">//  protected Paint calcGradientPaint(Gradient gradient,<br></td></tr
><tr
id=sl_svn7768_1466

><td class="source">//                                    float x1, float y1, float x2, float y2) {<br></td></tr
><tr
id=sl_svn7768_1467

><td class="source">//    if (gradient instanceof LinearGradient) {<br></td></tr
><tr
id=sl_svn7768_1468

><td class="source">//      LinearGradient grad = (LinearGradient) gradient;<br></td></tr
><tr
id=sl_svn7768_1469

><td class="source">//      return new LinearGradientPaint(x1, y1, x2, y2,<br></td></tr
><tr
id=sl_svn7768_1470

><td class="source">//                                     grad.offset, grad.color, grad.count,<br></td></tr
><tr
id=sl_svn7768_1471

><td class="source">//                                     opacity);<br></td></tr
><tr
id=sl_svn7768_1472

><td class="source">//    }<br></td></tr
><tr
id=sl_svn7768_1473

><td class="source">//    throw new RuntimeException(&quot;Not a linear gradient.&quot;);<br></td></tr
><tr
id=sl_svn7768_1474

><td class="source">//  }<br></td></tr
><tr
id=sl_svn7768_1475

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1476

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1477

><td class="source">//  protected Paint calcGradientPaint(Gradient gradient,<br></td></tr
><tr
id=sl_svn7768_1478

><td class="source">//                                    float cx, float cy, float r) {<br></td></tr
><tr
id=sl_svn7768_1479

><td class="source">//    if (gradient instanceof RadialGradient) {<br></td></tr
><tr
id=sl_svn7768_1480

><td class="source">//      RadialGradient grad = (RadialGradient) gradient;<br></td></tr
><tr
id=sl_svn7768_1481

><td class="source">//      return new RadialGradientPaint(cx, cy, r,<br></td></tr
><tr
id=sl_svn7768_1482

><td class="source">//                                     grad.offset, grad.color, grad.count,<br></td></tr
><tr
id=sl_svn7768_1483

><td class="source">//                                     opacity);<br></td></tr
><tr
id=sl_svn7768_1484

><td class="source">//    }<br></td></tr
><tr
id=sl_svn7768_1485

><td class="source">//    throw new RuntimeException(&quot;Not a radial gradient.&quot;);<br></td></tr
><tr
id=sl_svn7768_1486

><td class="source">//  }<br></td></tr
><tr
id=sl_svn7768_1487

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1488

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1489

><td class="source">  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .<br></td></tr
><tr
id=sl_svn7768_1490

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1491

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1492

><td class="source">  protected void styles(PGraphics g) {<br></td></tr
><tr
id=sl_svn7768_1493

><td class="source">    super.styles(g);<br></td></tr
><tr
id=sl_svn7768_1494

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1495

><td class="source">    if (g instanceof PGraphicsJava2D) {<br></td></tr
><tr
id=sl_svn7768_1496

><td class="source">      PGraphicsJava2D p2d = (PGraphicsJava2D) g;<br></td></tr
><tr
id=sl_svn7768_1497

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1498

><td class="source">      if (strokeGradient != null) {<br></td></tr
><tr
id=sl_svn7768_1499

><td class="source">        p2d.strokeGradient = true;<br></td></tr
><tr
id=sl_svn7768_1500

><td class="source">        p2d.strokeGradientObject = strokeGradientPaint;<br></td></tr
><tr
id=sl_svn7768_1501

><td class="source">      } else {<br></td></tr
><tr
id=sl_svn7768_1502

><td class="source">        // need to shut off, in case parent object has a gradient applied<br></td></tr
><tr
id=sl_svn7768_1503

><td class="source">        //p2d.strokeGradient = false;<br></td></tr
><tr
id=sl_svn7768_1504

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1505

><td class="source">      if (fillGradient != null) {<br></td></tr
><tr
id=sl_svn7768_1506

><td class="source">        p2d.fillGradient = true;<br></td></tr
><tr
id=sl_svn7768_1507

><td class="source">        p2d.fillGradientObject = fillGradientPaint;<br></td></tr
><tr
id=sl_svn7768_1508

><td class="source">      } else {<br></td></tr
><tr
id=sl_svn7768_1509

><td class="source">        // need to shut off, in case parent object has a gradient applied<br></td></tr
><tr
id=sl_svn7768_1510

><td class="source">        //p2d.fillGradient = false;<br></td></tr
><tr
id=sl_svn7768_1511

><td class="source">      }<br></td></tr
><tr
id=sl_svn7768_1512

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1513

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1514

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1515

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1516

><td class="source">  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .<br></td></tr
><tr
id=sl_svn7768_1517

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1518

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1519

><td class="source">  //public void drawImpl(PGraphics g) {<br></td></tr
><tr
id=sl_svn7768_1520

><td class="source">  // do nothing<br></td></tr
><tr
id=sl_svn7768_1521

><td class="source">  //}<br></td></tr
><tr
id=sl_svn7768_1522

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1523

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1524

><td class="source">  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .<br></td></tr
><tr
id=sl_svn7768_1525

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1526

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1527

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_1528

><td class="source">   * Get a particular element based on its SVG ID. When editing SVG by hand,<br></td></tr
><tr
id=sl_svn7768_1529

><td class="source">   * this is the id=&quot;&quot; tag on any SVG element. When editing from Illustrator,<br></td></tr
><tr
id=sl_svn7768_1530

><td class="source">   * these IDs can be edited by expanding the layers palette. The names used<br></td></tr
><tr
id=sl_svn7768_1531

><td class="source">   * in the layers palette, both for the layers or the shapes and groups<br></td></tr
><tr
id=sl_svn7768_1532

><td class="source">   * beneath them can be used here.<br></td></tr
><tr
id=sl_svn7768_1533

><td class="source">   * &lt;PRE&gt;<br></td></tr
><tr
id=sl_svn7768_1534

><td class="source">   * // This code grabs &quot;Layer 3&quot; and the shapes beneath it.<br></td></tr
><tr
id=sl_svn7768_1535

><td class="source">   * PShape layer3 = svg.getChild(&quot;Layer 3&quot;);<br></td></tr
><tr
id=sl_svn7768_1536

><td class="source">   * &lt;/PRE&gt;<br></td></tr
><tr
id=sl_svn7768_1537

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_1538

><td class="source">  public PShape getChild(String name) {<br></td></tr
><tr
id=sl_svn7768_1539

><td class="source">    PShape found = super.getChild(name);<br></td></tr
><tr
id=sl_svn7768_1540

><td class="source">    if (found == null) {<br></td></tr
><tr
id=sl_svn7768_1541

><td class="source">      // Otherwise try with underscores instead of spaces<br></td></tr
><tr
id=sl_svn7768_1542

><td class="source">      // (this is how Illustrator handles spaces in the layer names).<br></td></tr
><tr
id=sl_svn7768_1543

><td class="source">      found = super.getChild(name.replace(&#39; &#39;, &#39;_&#39;));<br></td></tr
><tr
id=sl_svn7768_1544

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1545

><td class="source">    // Set bounding box based on the parent bounding box<br></td></tr
><tr
id=sl_svn7768_1546

><td class="source">    if (found != null) {<br></td></tr
><tr
id=sl_svn7768_1547

><td class="source">//      found.x = this.x;<br></td></tr
><tr
id=sl_svn7768_1548

><td class="source">//      found.y = this.y;<br></td></tr
><tr
id=sl_svn7768_1549

><td class="source">      found.width = this.width;<br></td></tr
><tr
id=sl_svn7768_1550

><td class="source">      found.height = this.height;<br></td></tr
><tr
id=sl_svn7768_1551

><td class="source">    }<br></td></tr
><tr
id=sl_svn7768_1552

><td class="source">    return found;<br></td></tr
><tr
id=sl_svn7768_1553

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1554

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1555

><td class="source"><br></td></tr
><tr
id=sl_svn7768_1556

><td class="source">  /**<br></td></tr
><tr
id=sl_svn7768_1557

><td class="source">   * Prints out the SVG document. Useful for parsing.<br></td></tr
><tr
id=sl_svn7768_1558

><td class="source">   */<br></td></tr
><tr
id=sl_svn7768_1559

><td class="source">  public void print() {<br></td></tr
><tr
id=sl_svn7768_1560

><td class="source">    PApplet.println(element.toString());<br></td></tr
><tr
id=sl_svn7768_1561

><td class="source">  }<br></td></tr
><tr
id=sl_svn7768_1562

><td class="source">}<br></td></tr
></table></pre>
<pre class="prettyprint"><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
</td>
</tr></table>
<script type="text/javascript">
 var lineNumUnderMouse = -1;
 
 function gutterOver(num) {
 gutterOut();
 var newTR = document.getElementById('gr_svn7768_' + num);
 if (newTR) {
 newTR.className = 'undermouse';
 }
 lineNumUnderMouse = num;
 }
 function gutterOut() {
 if (lineNumUnderMouse != -1) {
 var oldTR = document.getElementById(
 'gr_svn7768_' + lineNumUnderMouse);
 if (oldTR) {
 oldTR.className = '';
 }
 lineNumUnderMouse = -1;
 }
 }
 var numsGenState = {table_base_id: 'nums_table_'};
 var srcGenState = {table_base_id: 'src_table_'};
 var alignerRunning = false;
 var startOver = false;
 function setLineNumberHeights() {
 if (alignerRunning) {
 startOver = true;
 return;
 }
 numsGenState.chunk_id = 0;
 numsGenState.table = document.getElementById('nums_table_0');
 numsGenState.row_num = 0;
 srcGenState.chunk_id = 0;
 srcGenState.table = document.getElementById('src_table_0');
 srcGenState.row_num = 0;
 alignerRunning = true;
 continueToSetLineNumberHeights();
 }
 function rowGenerator(genState) {
 if (genState.row_num < genState.table.rows.length) {
 var currentRow = genState.table.rows[genState.row_num];
 genState.row_num++;
 return currentRow;
 }
 var newTable = document.getElementById(
 genState.table_base_id + (genState.chunk_id + 1));
 if (newTable) {
 genState.chunk_id++;
 genState.row_num = 0;
 genState.table = newTable;
 return genState.table.rows[0];
 }
 return null;
 }
 var MAX_ROWS_PER_PASS = 1000;
 function continueToSetLineNumberHeights() {
 var rowsInThisPass = 0;
 var numRow = 1;
 var srcRow = 1;
 while (numRow && srcRow && rowsInThisPass < MAX_ROWS_PER_PASS) {
 numRow = rowGenerator(numsGenState);
 srcRow = rowGenerator(srcGenState);
 rowsInThisPass++;
 if (numRow && srcRow) {
 if (numRow.offsetHeight != srcRow.offsetHeight) {
 numRow.firstChild.style.height = srcRow.offsetHeight + 'px';
 }
 }
 }
 if (rowsInThisPass >= MAX_ROWS_PER_PASS) {
 setTimeout(continueToSetLineNumberHeights, 10);
 } else {
 alignerRunning = false;
 if (startOver) {
 startOver = false;
 setTimeout(setLineNumberHeights, 500);
 }
 }
 }
 // Do 2 complete passes, because there can be races
 // between this code and prettify.
 startOver = true;
 setTimeout(setLineNumberHeights, 250);
 window.onresize = setLineNumberHeights;
</script>

 
 
 <div id="log">
 <div style="text-align:right">
 <a class="ifCollapse" href="#" onclick="_toggleMeta('', 'p', 'processing', this)">Show details</a>
 <a class="ifExpand" href="#" onclick="_toggleMeta('', 'p', 'processing', this)">Hide details</a>
 </div>
 <div class="ifExpand">
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="changelog">
 <p>Change log</p>
 <div>
 <a href="/p/processing/source/detail?spec=svn7768&r=7554">r7554</a>
 by f...@processing.org
 on Jan 20, 2011
 &nbsp; <a href="/p/processing/source/diff?spec=svn7768&r=7554&amp;format=side&amp;path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old_path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old=7117">Diff</a>
 </div>
 <pre>moving things back off the branch, and
into full disaster mode</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/processing/source/detail?r=7554&spec=svn7768';
 var publish_url = '/p/processing/source/detail?r=7554&spec=svn7768#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/processing/android/core/src/processing/core/PShape3D.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/core/src/processing/core/PShape3D.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/core/src/processing/core/PTexture.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/core/src/processing/core/PTexture.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/done.txt');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/done.txt?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/todo.txt');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/todo.txt?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/tool/src/processing/app/tools/android/AndroidDevice.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/AndroidDevice.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/tool/src/processing/app/tools/android/AndroidMode.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/AndroidMode.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/tool/src/processing/app/tools/android/Build.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Build.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/tool/src/processing/app/tools/android/Manifest.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Manifest.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/tool/src/processing/app/tools/android/Permissions.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Permissions.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/android/tool/src/processing/app/tools/android/Preprocessor.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Preprocessor.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/.settings/org.eclipse.jdt.core.prefs');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/.settings/org.eclipse.jdt.core.prefs?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/ParserTests.launch');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/ParserTests.launch?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/generated/processing/mode');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/generated/processing/mode?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/generated/processing/mode/java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/generated/processing/mode/java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/generated/processing/mode/java/preproc');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/generated/processing/mode/java/preproc?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/grammars');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/grammars?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/antlr');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/antlr?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/antlr/ExtendedCommonASTWithHiddenTokens.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/antlr/ExtendedCommonASTWithHiddenTokens.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/antlr/TokenStreamCopyingHiddenTokenFilter.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/antlr/TokenStreamCopyingHiddenTokenFilter.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Base.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Base.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Commander.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Commander.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Editor.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Editor.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/EditorConsole.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorConsole.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/EditorHeader.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorHeader.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/EditorLineStatus.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorLineStatus.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/EditorListener.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorListener.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/EditorStatus.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorStatus.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/EditorToolbar.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorToolbar.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Formatter.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Formatter.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Library.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Library.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/LibraryFolder.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/LibraryFolder.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Mode.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Mode.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Preferences.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Preferences.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/PresentMode.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/PresentMode.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/RunnerListener.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/RunnerListener.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Settings.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Settings.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Sketch.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Sketch.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/SketchCode.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/SketchCode.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/SketchException.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/SketchException.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/Theme.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/Theme.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/debug');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/debug?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/format');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/format?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/macosx/ThinkDifferent.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/macosx/ThinkDifferent.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/preproc');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/preproc?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/syntax/CTokenMarker.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/CTokenMarker.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/syntax/JEditTextArea.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/JEditTextArea.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/syntax/PdeKeywords.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/PdeKeywords.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/syntax/PdeTextAreaDefaults.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/PdeTextAreaDefaults.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/syntax/TextAreaDefaults.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/TextAreaDefaults.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 changed_paths.push('/trunk/processing/app/src/processing/app/syntax/TextAreaPainter.java');
 changed_urls.push('/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/TextAreaPainter.java?r\x3d7554\x26spec\x3dsvn7768');
 
 
 function getCurrentPageIndex() {
 for (var i = 0; i < changed_paths.length; i++) {
 if (selected_path == changed_paths[i]) {
 return i;
 }
 }
 }
 function getNextPage() {
 var i = getCurrentPageIndex();
 if (i < changed_paths.length - 1) {
 return changed_urls[i + 1];
 }
 return null;
 }
 function getPreviousPage() {
 var i = getCurrentPageIndex();
 if (i > 0) {
 return changed_urls[i - 1];
 }
 return null;
 }
 function gotoNextPage() {
 var page = getNextPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoPreviousPage() {
 var page = getPreviousPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoDetailPage() {
 window.location = detail_url;
 }
 function gotoPublishPage() {
 window.location = publish_url;
 }
</script>

 
 <style type="text/css">
 #review_nav {
 border-top: 3px solid white;
 padding-top: 6px;
 margin-top: 1em;
 }
 #review_nav td {
 vertical-align: middle;
 }
 #review_nav select {
 margin: .5em 0;
 }
 </style>
 <div id="review_nav">
 <table><tr><td>Go to:&nbsp;</td><td>
 <select name="files_in_rev" onchange="window.location=this.value">
 
 <option value="/p/processing/source/browse/trunk/processing/android/core/src/processing/core/PShape3D.java?r=7554&amp;spec=svn7768"
 
 >...rc/processing/core/PShape3D.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/core/src/processing/core/PTexture.java?r=7554&amp;spec=svn7768"
 
 >...rc/processing/core/PTexture.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/done.txt?r=7554&amp;spec=svn7768"
 
 >/trunk/processing/android/done.txt</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/todo.txt?r=7554&amp;spec=svn7768"
 
 >/trunk/processing/android/todo.txt</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/AndroidDevice.java?r=7554&amp;spec=svn7768"
 
 >...tools/android/AndroidDevice.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/AndroidMode.java?r=7554&amp;spec=svn7768"
 
 >...p/tools/android/AndroidMode.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Build.java?r=7554&amp;spec=svn7768"
 
 >...ing/app/tools/android/Build.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Manifest.java?r=7554&amp;spec=svn7768"
 
 >.../app/tools/android/Manifest.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Permissions.java?r=7554&amp;spec=svn7768"
 
 >...p/tools/android/Permissions.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/android/tool/src/processing/app/tools/android/Preprocessor.java?r=7554&amp;spec=svn7768"
 
 >.../tools/android/Preprocessor.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/.settings/org.eclipse.jdt.core.prefs?r=7554&amp;spec=svn7768"
 
 >...tings/org.eclipse.jdt.core.prefs</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/ParserTests.launch?r=7554&amp;spec=svn7768"
 
 >...rocessing/app/ParserTests.launch</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/generated/processing/mode?r=7554&amp;spec=svn7768"
 
 >...ng/app/generated/processing/mode</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/generated/processing/mode/java?r=7554&amp;spec=svn7768"
 
 >...p/generated/processing/mode/java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/generated/processing/mode/java/preproc?r=7554&amp;spec=svn7768"
 
 >...ted/processing/mode/java/preproc</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/grammars?r=7554&amp;spec=svn7768"
 
 >/trunk/processing/app/grammars</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/antlr?r=7554&amp;spec=svn7768"
 
 >/trunk/processing/app/src/antlr</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/antlr/ExtendedCommonASTWithHiddenTokens.java?r=7554&amp;spec=svn7768"
 
 >...edCommonASTWithHiddenTokens.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/antlr/TokenStreamCopyingHiddenTokenFilter.java?r=7554&amp;spec=svn7768"
 
 >...eamCopyingHiddenTokenFilter.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Base.java?r=7554&amp;spec=svn7768"
 
 >...app/src/processing/app/Base.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Commander.java?r=7554&amp;spec=svn7768"
 
 >...rc/processing/app/Commander.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Editor.java?r=7554&amp;spec=svn7768"
 
 >...p/src/processing/app/Editor.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorConsole.java?r=7554&amp;spec=svn7768"
 
 >...rocessing/app/EditorConsole.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorHeader.java?r=7554&amp;spec=svn7768"
 
 >...processing/app/EditorHeader.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorLineStatus.java?r=7554&amp;spec=svn7768"
 
 >...essing/app/EditorLineStatus.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorListener.java?r=7554&amp;spec=svn7768"
 
 >...ocessing/app/EditorListener.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorStatus.java?r=7554&amp;spec=svn7768"
 
 >...processing/app/EditorStatus.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/EditorToolbar.java?r=7554&amp;spec=svn7768"
 
 >...rocessing/app/EditorToolbar.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Formatter.java?r=7554&amp;spec=svn7768"
 
 >...rc/processing/app/Formatter.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Library.java?r=7554&amp;spec=svn7768"
 
 >.../src/processing/app/Library.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/LibraryFolder.java?r=7554&amp;spec=svn7768"
 
 >...rocessing/app/LibraryFolder.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Mode.java?r=7554&amp;spec=svn7768"
 
 >...app/src/processing/app/Mode.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Preferences.java?r=7554&amp;spec=svn7768"
 
 >.../processing/app/Preferences.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/PresentMode.java?r=7554&amp;spec=svn7768"
 
 >.../processing/app/PresentMode.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/RunnerListener.java?r=7554&amp;spec=svn7768"
 
 >...ocessing/app/RunnerListener.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Settings.java?r=7554&amp;spec=svn7768"
 
 >...src/processing/app/Settings.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Sketch.java?r=7554&amp;spec=svn7768"
 
 >...p/src/processing/app/Sketch.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/SketchCode.java?r=7554&amp;spec=svn7768"
 
 >...c/processing/app/SketchCode.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/SketchException.java?r=7554&amp;spec=svn7768"
 
 >...cessing/app/SketchException.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/Theme.java?r=7554&amp;spec=svn7768"
 
 >...pp/src/processing/app/Theme.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/debug?r=7554&amp;spec=svn7768"
 
 >...ing/app/src/processing/app/debug</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/format?r=7554&amp;spec=svn7768"
 
 >...ng/app/src/processing/app/format</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/macosx/ThinkDifferent.java?r=7554&amp;spec=svn7768"
 
 >...g/app/macosx/ThinkDifferent.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/preproc?r=7554&amp;spec=svn7768"
 
 >...g/app/src/processing/app/preproc</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/CTokenMarker.java?r=7554&amp;spec=svn7768"
 
 >...ing/app/syntax/CTokenMarker.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/JEditTextArea.java?r=7554&amp;spec=svn7768"
 
 >...ng/app/syntax/JEditTextArea.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/PdeKeywords.java?r=7554&amp;spec=svn7768"
 
 >...sing/app/syntax/PdeKeywords.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/PdeTextAreaDefaults.java?r=7554&amp;spec=svn7768"
 
 >.../syntax/PdeTextAreaDefaults.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/TextAreaDefaults.java?r=7554&amp;spec=svn7768"
 
 >...app/syntax/TextAreaDefaults.java</option>
 
 <option value="/p/processing/source/browse/trunk/processing/app/src/processing/app/syntax/TextAreaPainter.java?r=7554&amp;spec=svn7768"
 
 >.../app/syntax/TextAreaPainter.java</option>
 
 </select>
 </td></tr></table>
 
 
 



 
 </div>
 
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="older_bubble">
 <p>Older revisions</p>
 
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/processing/source/detail?spec=svn7768&r=7117">r7117</a>
 by f...@processing.org
 on Jul 17, 2010
 &nbsp; <a href="/p/processing/source/diff?spec=svn7768&r=7117&amp;format=side&amp;path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old_path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old=7006">Diff</a>
 <br>
 <pre class="ifOpened">add getBoolean(), deprecate the
getAttributeXxxx(), add
listChildren(), more cleanup on
indents and namespace mess
</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/processing/source/detail?spec=svn7768&r=7006">r7006</a>
 by f...@processing.org
 on Jun 25, 2010
 &nbsp; <a href="/p/processing/source/diff?spec=svn7768&r=7006&amp;format=side&amp;path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old_path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old=7002">Diff</a>
 <br>
 <pre class="ifOpened">doc tweaks
</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/processing/source/detail?spec=svn7768&r=7002">r7002</a>
 by f...@processing.org
 on Jun 25, 2010
 &nbsp; <a href="/p/processing/source/diff?spec=svn7768&r=7002&amp;format=side&amp;path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old_path=/trunk/processing/core/src/processing/core/PShapeSVG.java&amp;old=6691">Diff</a>
 <br>
 <pre class="ifOpened">fixes for bad regexp being used with
the adobe stuff
</pre>
 </div>
 
 
 <a href="/p/processing/source/list?path=/trunk/processing/core/src/processing/core/PShapeSVG.java&start=7554">All revisions of this file</a>
 </div>
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="fileinfo_bubble">
 <p>File info</p>
 
 <div>Size: 50958 bytes,
 1562 lines</div>
 
 <div><a href="http://processing.googlecode.com/svn/trunk/processing/core/src/processing/core/PShapeSVG.java">View raw file</a></div>
 </div>
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 </div>
 </div>


</div>

</div>
</div>

<script src="http://www.gstatic.com/codesite/ph/10276742928614796628/js/prettify/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script src="http://www.gstatic.com/codesite/ph/10276742928614796628/js/source_file_scripts.js"></script>

 <script type="text/javascript" src="https://kibbles.googlecode.com/files/kibbles-1.3.3.comp.js"></script>
 <script type="text/javascript">
 var lastStop = null;
 var initilized = false;
 
 function updateCursor(next, prev) {
 if (prev && prev.element) {
 prev.element.className = 'cursor_stop cursor_hidden';
 }
 if (next && next.element) {
 next.element.className = 'cursor_stop cursor';
 lastStop = next.index;
 }
 }
 
 function pubRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initilized) {
 reloadCursors();
 }
 }
 
 function draftRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initilized) {
 reloadCursors();
 }
 }
 
 function draftDestroyed(data) {
 updateCursorForCell(data.cellId, 'nocursor');
 if (initilized) {
 reloadCursors();
 }
 }
 function reloadCursors() {
 kibbles.skipper.reset();
 loadCursors();
 if (lastStop != null) {
 kibbles.skipper.setCurrentStop(lastStop);
 }
 }
 // possibly the simplest way to insert any newly added comments
 // is to update the class of the corresponding cursor row,
 // then refresh the entire list of rows.
 function updateCursorForCell(cellId, className) {
 var cell = document.getElementById(cellId);
 // we have to go two rows back to find the cursor location
 var row = getPreviousElement(cell.parentNode);
 row.className = className;
 }
 // returns the previous element, ignores text nodes.
 function getPreviousElement(e) {
 var element = e.previousSibling;
 if (element.nodeType == 3) {
 element = element.previousSibling;
 }
 if (element && element.tagName) {
 return element;
 }
 }
 function loadCursors() {
 // register our elements with skipper
 var elements = CR_getElements('*', 'cursor_stop');
 var len = elements.length;
 for (var i = 0; i < len; i++) {
 var element = elements[i]; 
 element.className = 'cursor_stop cursor_hidden';
 kibbles.skipper.append(element);
 }
 }
 function toggleComments() {
 CR_toggleCommentDisplay();
 reloadCursors();
 }
 function keysOnLoadHandler() {
 // setup skipper
 kibbles.skipper.addStopListener(
 kibbles.skipper.LISTENER_TYPE.PRE, updateCursor);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_top', 50);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_bottom', 100);
 // Register our keys
 kibbles.skipper.addFwdKey("n");
 kibbles.skipper.addRevKey("p");
 kibbles.keys.addKeyPressListener(
 'u', function() { window.location = detail_url; });
 kibbles.keys.addKeyPressListener(
 'r', function() { window.location = detail_url + '#publish'; });
 
 kibbles.keys.addKeyPressListener('j', gotoNextPage);
 kibbles.keys.addKeyPressListener('k', gotoPreviousPage);
 
 
 }
 </script>
<script src="http://www.gstatic.com/codesite/ph/10276742928614796628/js/code_review_scripts.js"></script>
<script type="text/javascript">
 
 // the comment form template
 var form = '<div class="draft"><div class="header"><span class="title">Draft comment:</span></div>' +
 '<div class="body"><form onsubmit="return false;"><textarea id="$ID">$BODY</textarea><br>$ACTIONS</form></div>' +
 '</div>';
 // the comment "plate" template used for both draft and published comment "plates".
 var draft_comment = '<div class="draft" ondblclick="$ONDBLCLICK">' +
 '<div class="header"><span class="title">Draft comment:</span><span class="actions">$ACTIONS</span></div>' +
 '<pre id="$ID" class="body">$BODY</pre>' +
 '</div>';
 var published_comment = '<div class="published">' +
 '<div class="header"><span class="title"><a href="$PROFILE_URL">$AUTHOR:</a></span><div>' +
 '<pre id="$ID" class="body">$BODY</pre>' +
 '</div>';

 function showPublishInstructions() {
 var element = document.getElementById('review_instr');
 if (element) {
 element.className = 'opened';
 }
 }
 function revsOnLoadHandler() {
 // register our source container with the commenting code
 var paths = {'svn7768': '/trunk/processing/core/src/processing/core/PShapeSVG.java'}
 CR_setup('', 'p', 'processing', '', 'svn7768', paths,
 'c6974bcd72eb95455827185f7306e1fa', CR_BrowseIntegrationFactory);
 // register our hidden ui elements with the code commenting code ui builder.
 CR_registerLayoutElement('form', form);
 CR_registerLayoutElement('draft_comment', draft_comment);
 CR_registerLayoutElement('published_comment', published_comment);
 
 CR_registerActivityListener(CR_ACTIVITY_TYPE.REVEAL_DRAFT_PLATE, showPublishInstructions);
 
 CR_registerActivityListener(CR_ACTIVITY_TYPE.REVEAL_PUB_PLATE, pubRevealed);
 CR_registerActivityListener(CR_ACTIVITY_TYPE.REVEAL_DRAFT_PLATE, draftRevealed);
 CR_registerActivityListener(CR_ACTIVITY_TYPE.DISCARD_DRAFT_COMMENT, draftDestroyed);
 
 
 
 
 
 
 
 var initilized = true;
 reloadCursors();
 }
 window.onload = function() {keysOnLoadHandler(); revsOnLoadHandler();};

</script>
<script type="text/javascript" src="http://www.gstatic.com/codesite/ph/10276742928614796628/js/dit_scripts.js"></script>

 
 
 <script type="text/javascript" src="http://www.gstatic.com/codesite/ph/10276742928614796628/js/core_scripts_20081103.js"></script>
 <script type="text/javascript" src="/js/codesite_product_dictionary_ph.pack.04102009.js"></script>
</div> 
<div id="footer" dir="ltr">
 
 <div class="text">
 
 &copy;2010 Google -
 <a href="/projecthosting/terms.html">Terms</a> -
 <a href="http://www.google.com/privacy.html">Privacy</a> -
 <a href="/p/support/">Project Hosting Help</a>
 
 </div>
</div>
 <div class="hostedBy" style="margin-top: -20px;">
 <span style="vertical-align: top;">Powered by <a href="http://code.google.com/projecthosting/">Google Project Hosting</a></span>
 </div>
 
 


 
 
 <script type="text/javascript">_CS_reportToCsi();</script>
 
 </body>
</html>

