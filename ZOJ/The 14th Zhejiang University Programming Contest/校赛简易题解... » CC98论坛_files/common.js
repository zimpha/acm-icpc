//2006-12-03  slepher为firefox添加popuptext支持
//2004-11-25  cftc增添music下拉菜单
//2004-12-15  cftc增添blog下拉菜单
//2004-12-29  diogin简化链接样式
//2007-12-7 sxyag vDiv改成display=none以修正下拉菜单老是脚本错误
//2012-9-29 Sakura 增加回帖情况查询


//用户控制面板
var manage1 = '<a class=mainjs href=\"https://secure.cc98.org/Register\">注册</a><br><a class=mainjs href=\"login.asp\">登录</a>'

var manage2 = '<a class=mainjs href=\"JavaScript:openScript(\'messanger.asp?action=new\',500,400);\">发短信</a><br><a class=mainjs href=\"info_userpermission.asp\">我能做什么</a><br><a class=mainjs href=\"modifyinfo.asp\">编辑个人资料</a><br><a class=mainjs href=\"modifypsw.asp\">用户密码修改</a><br><a class=mainjs href=\"usersms.asp?action=friend\">编辑好友列表</a><br><a class=mainjs href=\"favlist.asp\">用户收藏管理</a><br><a class=mainjs href=\"user_bbseven.asp\">我的论坛事件</a><br><a class=mainjs href=\"mytopic.asp\">我发表的主题</a>'

var logon = '<a class=mainjs href="cookies.asp?action=hidden">隐身</a><br><a class=mainjs href="cookies.asp?action=online">上线</a><br><a class=mainjs href="login.asp">重新登录</a><br><a class=mainjs href="javascript:;" onclick="sign.Out()">取消登录</a>'

//论坛状态
var boardstat = '<a class=mainjs href=\"boardstat.asp?boardid=' + currentBoardID + '\">今日贴数图例</a><br><a class=mainjs href=\"boardstat.asp?action=lasttopicnum&boardid=' + currentBoardID + '\">主题数图例</a><br><a class=mainjs href=\"boardstat.asp?action=lastbbsnum&boardid=' + currentBoardID + '\">总帖数图例</a><br><a class=mainjs href=\"boardstat.asp?reaction=online&boardid=' + currentBoardID + '\">在线图例</a><br><a class=mainjs href=\"boardstat.asp?reaction=onlineinfo&boardid=' + currentBoardID + '\">在线情况</a><br><a class=mainjs href=\"boardstat.asp?reaction=onlineUserinfo&boardid=' + currentBoardID + '\">用户组在线图例</a>'

//热门版面
//var hotboard= '<a class=mainjs href=\"list.asp?boardid=202\">网络资源</a><br><a class=mainjs href=\"list.asp?boardid=198\">新生宝典</a><br><a class=mainjs href=\"list.asp?boardid=235\">求职广场</a><br><a class=mainjs href=\"list.asp?boardid=234\">TV满屋</a><br><a class=mainjs href=\"list.asp?boardid=226\">电脑医院</a><br>'

//附加功能
var addon = '<a class="mainjs" href="http://share.cc98.org" target="_blank">CC98 Share </a><br /><a class="mainjs" href="game.asp">CC98 Game(RC1)</a><br /><a class="mainjs" href="http://v2.cc98.org/app/medalmanager.aspx">CC98 勋章中心</a><br /><a class="mainjs" href="football.asp">CC98 足彩</a><br /><a class="mainjs" href="Subdomain.asp">CC98 二级域名(维护ing..)</a><br /><!--<a class=mainjs href=\"http://blog.cc98.org\">Blog</a><br />--><a class="mainjs" href="music.asp">CC98 点歌台</a><br /><!--<a class=mainjs href=\"music_brocast.asp\">广播台点歌</a><br>--><a class=mainjs href=\"http://team.cc98.org/showtopic-11.aspx\" target=\"_blank\">Windows升级服务</a><br><a class=mainjs href=\"MicShow.asp\">自唱音乐展区</a><br><a class=mainjs href=\"findpwd.asp\">自助密码找回</a><br><a class=mainjs href=\"publicvotelist.asp\">论坛投票</a><br><a class=mainjs href=\"reserveuser.asp\">荣誉会员申请</a><br><a class=mainjs href=\"ubbconvert.asp\" target=\"about:_blank\">转贴工具</a><!--<br /><a class=mainjs href=\"http://offer.cc98.org\" target=\"about:_blank\">Offer Boomer</a>--><br /><a class=mainjs href=\"cleartopic.asp\" target=\"_blank\">帖子清理</a><br />'

//管理工具
var mastertools = '<a class=mainjs href=\"recycle.asp\">回收站</a><br><a class=mainjs href=\"viewmj.asp">MJ查看器</a><br><a class=mainjs href=\"viewlock.asp\">锁定用户查看</a><br><a class=mainjs href=\"master_reserveuser.asp\">ID永久保存审核</a><br><a class=mainjs href=\"cert.asp" target="_blank">证书生成器</a><br /><a class=mainjs href=\"show.asp">展区</a><br><a class=mainjs href=\"addon_admin.asp\">附加功能管理</a><br><a class=mainjs href=\"master_paper.asp\">小字报管理</a><br><a class=mainjs href=\"Admin_EventView.asp\">管理事件查询</a><br><a class=mainjs href=\"Admin_PostView.asp\">回帖情况查询</a><br /><a class=mainjs href=\"master_stopposts.asp\">全站TP管理</a>'

//论坛帮助
var help = '<a class=mainjs href=\"FAQ.asp\">常见问题</a><br><A class=mainjs HREF=\"boardhelp.asp#point\">积分设置</A><br><A class=mainjs HREF=\"boardhelp.asp#grade\">等级设置</A><br><A class=mainjs HREF=\"boardhelp.asp#ubb\">UBB语法</A><br><A class=mainjs HREF=\"boardhelp.asp#ubb1\">论坛常见问题</A><br><A class=mainjs HREF=\"boardhelp.asp#other\">其他论坛设置</A>'

var Search = '<a class="mainjs" href="#" id="boardQueryLink2">版面搜索</a><br><a class="mainjs" href="query.asp?boardid=' + currentBoardID + '">帖子搜索</a>'
//blog
//var blog= '<a class=mainjs href=\"http://10.71.45.100/blog\">旧版blog</a><br><a class=mainjs href=\"http://10.71.45.100/newblog\">新版blog</a><br>'

//点歌
//var music= '<a class=mainjs href=\"music.asp\">论坛点歌</a><br><a class=mainjs href=\"music_brocast.asp\">广播台点歌</a><br>'

//论坛娱乐区
//var fun= '<a class=mainjs href=\"test.asp\">开心词典</a><br><a class=mainjs href=\"diao.asp\">渔人码头</a><br><a class=mainjs href=\"bank.asp\">社区银行</a><br><a class=mainjs href=\"play.asp\">超级赌场</a><br><a class=mainjs href=\"caipiao.asp\">彩票中心</a><br><a class=mainjs href=\"indexsheep.asp\">社区牧场</a><br><a class=mainjs href=\"jieindex.asp\">月下老人</a>'

var sign = {
	'In': function () {
		var loginForm = $('loginForm');
		if ($('userName').value == '') {
			this.Do(101);
			return false;
		} else {
			var userName = $('userName').value;
		};
		if ($('password').value == '') {
			this.Do(102);
			return false;
		} else {
			var password = $('password').value;
			$('password').value = '';
		};
		var userHidden = !!getRadio('userhidden') ? getRadio('userhidden').value : 2;
		var comeUrl = $('comeUrl') ? $('comeUrl').value : 'index.asp';
		var data = 'a=i&u=' + encodeURIComponent(userName) + '&p=' + hex_md5(password) + '&userhidden=' + userHidden
		var signIn = new Request({
			url: 'sign.asp',
			method: 'post',
			onSuccess: function (responseText, responseXML) {
				this.Do(responseText, signIn, comeUrl);
			}.bind(this),
			onFailure: function (xhr) {
				if (Cookie.read('aspsky') && Browser.Engine.trident) {
					Cookie.dispose('aspsky');
				}
				this.Do(103);
			}.bind(this)
		});
		signIn.send(data);
		Cookie.write('upNum', 0);
		return false;
	},
	'Out': function () {
		if (Cookie.read('aspsky')) {
			var o = new Request({
				url: 'sign.asp', method: 'post', async: false, onComplete: function () {
					Cookie.dispose('aspsky');
				}
			}).send('a=o');
		}
		location.reload();
	},
	'Do': function (errCode, xhr, comeUrl) {
		if (!!xhr && xhr.getHeader('Set-Cookie')) {
			if (Cookie.read('aspsky') && Browser.Engine.trident) {
				Cookie.dispose('aspsky');
			}
			document.cookie = xhr.getHeader('Set-Cookie');
		}
		switch (errCode.toInt()) {
			case 9898: $('loginTip').innerHTML = '登录成功，正在跳转！'; if (!!comeUrl) { location.href = comeUrl; } else { location.href = 'index.asp?'; }; break;
			case 101: $('loginTip').innerHTML = '用户名不能为空！'; $('userName').focus(); break;
			case 102: $('loginTip').innerHTML = '密码不能为空！'; $('password').focus(); break;
			case 103: $('loginTip').innerHTML = 'xmlHttp请求失败！'; break;
			case 1001: $('loginTip').innerHTML = '该用户名不存在，请检查用户名是否正确！'; $('userName').focus(); break;
			case 1002: $('loginTip').innerHTML = '该用户已被锁定，如果疑问请联系站务组'; break;
			case 1003: $('loginTip').innerHTML = '密码错误! 啥？忘记密码了？到<a href="findpwd.asp" style="color:blue;">这里</a>去找找看嘛'; $('password').focus(); break;
			default: $('loginTip').innerHTML = 'Error Code:' + errCode.toInt() + ';未知错误，请联系技术组获取帮助！'; break;
		};
	}
};

var getRadio = function (rm) {
	if ($$('input[name=' + rm + '][checked]').length > 0) {
		return $$('input[name=' + rm + '][checked]')[0];
	} else {
		return null;
	}
};

var changeSimple = function (isSimple) {
	var myCookie = Cookie.write('cc98Simple', isSimple == 1 ? 1 : 0, { duration: 365 });
	location.reload();
}

var changeSimple = function (isSimple) {
	var myCookie = Cookie.write('cc98Simple', isSimple == 1 ? 1 : 0, { duration: 365 });
	location.reload();
}

var strlen = function (str) {
	var len = 0;
	for (var i = 0; i < str.length; i++) {
		len += str.charCodeAt(i) < 0 || str.charCodeAt(i) > 255 ? 2 : 1;
	}
	return len;
}

var showadvs = function (flag) {
	var timeID;
	if (flag == 1) {
		var n = $random(0, 9);
		if (n < bannerInfo.t.length && bannerInfo.t.length > 0) {
			$('advImg').setStyle('background-image', 'url(' + bannerPath + bannerInfo.t[n].p + ')');
			$('advLink').href = 'advsredirect.asp?id=' + bannerInfo.t[n].i.toString();
		} else if (bannerInfo.b.length > 0) {
			n = $random(0, bannerInfo.b.length - 1);
			$('advImg').setStyle('background-image', 'url(' + bannerPath + bannerInfo.b[n].p + ')');
			$('advLink').href = 'advsredirect.asp?id=' + bannerInfo.b[n].i.toString();
		}
		timeID = (function () { showadvs(0); }).delay(20000);
	} else {
		$('advImg').setStyle('background', 'url(../images/spinner.gif) no-repeat center');
		$('advLink').href = '#';
		timeID = (function () { showadvs(1); }).delay(3000);
	}
}

function openScript(url, width, height) {
	var Win = window.open(url, "openScript", 'width=' + width + ',height=' + height + ',resizable=1,scrollbars=yes,menubar=no,status=yes');
}

//***********默认设置定义.*********************
tPopWait = 50;//停留tWait豪秒后显示提示。
tPopShow = 5000;//显示tShow豪秒后关闭提示
showPopStep = 20;
popOpacity = 99;
alphanow = 0;


//***************内部变量定义*****************
sPop = null;
curShow = null;
tFadeOut = null;
tFadeIn = null;
tFadeWaiting = null;

document.write("<style type='text/css'id='defaultPopStyle'>");
document.write(".cPopText {  background-color: #F8F8F5;color:#000000; border: 1px #000000 solid;font-color: font-size: 12px; padding-right: 4px; padding-left: 4px; height: 20px; padding-top: 2px; padding-bottom: 2px; filter: Alpha(Opacity=0)}");
document.write("</style>");
document.write("<div id='dypopLayer' style='position: absolute; z-index: 1000;height: auto;width: auto;visibility: hidden' class='cPopText'></div>");

function showPopupText(event) {
	if (event.srcElement) {
		o = event.srcElement;
		MouseX = event.x;
		MouseY = event.y;
	} else if (event.target) {
		o = event.target;//(谁把fadein/fadeout两个函数里alpha搞定再打开)
		MouseX = event.clientX;
		MouseY = event.clientY;
	} else {
		return;
	}
	if (o.alt != null && o.alt != "") { o.dypop = o.alt; o.alt = "" };
	if (o.title != null && o.title != "") { o.dypop = o.title; o.title = "" };
	if (o.dypop != sPop) {
		var dypopLayer = document.getElementById("dypopLayer");
		sPop = o.dypop;
		clearTimeout(curShow);
		clearTimeout(tFadeOut);
		clearTimeout(tFadeIn);
		clearTimeout(tFadeWaiting);
		if (sPop == null || sPop == "") {
			dypopLayer.innerHTML = "";
			if (event.srcElement)
				dypopLayer.style.filter = "Alpha()";
			//dypopLayer.filters.Alpha.opacity=0;	
			SetAlpha(dypopLayer, 0);
		}
		else {
			if (o.dyclass != null) { popStyle = o.dyclass; }
			else { popStyle = "cPopText"; }
			curShow = setTimeout("showIt()", tPopWait);
		}
	}
}

function showIt() {
	var dypopLayer = document.getElementById("dypopLayer");
	dypopLayer.className = popStyle;
	dypopLayer.innerHTML = sPop;
	popWidth = dypopLayer.clientWidth;
	popHeight = dypopLayer.clientHeight;
	if (MouseX + 12 + popWidth > document.body.clientWidth) popLeftAdjust = -popWidth - 24
	else popLeftAdjust = 0;
	if (MouseY + 12 + popHeight > document.body.clientHeight) popTopAdjust = -popHeight - 24
	else popTopAdjust = 0;
	dypopLayer.style.left = MouseX + 12 + document.body.scrollLeft + popLeftAdjust;
	dypopLayer.style.top = MouseY + 12 + document.body.scrollTop + popTopAdjust;
	//dypopLayer.style.filter="Alpha(Opacity=0)";
	SetAlpha(dypopLayer, 0);
	fadeOut();
	dypopLayer.style.visibility = "visible";
}

function fadeOut() {
	var dypopLayer = document.getElementById("dypopLayer");
	if (alphanow < popOpacity) {
		SetAlpha(dypopLayer, alphanow + showPopStep);
		tFadeOut = setTimeout("fadeOut()", 1);
	}
	else {
		SetAlpha(dypopLayer, popOpacity);
		tFadeWaiting = setTimeout("fadeIn()", tPopShow);
	}
}
function fadeIn() {
	var dypopLayer = document.getElementById("dypopLayer");
	if (alphanow > 0) {
		SetAlpha(dypopLayer, alphanow - 1);
		tFadeIn = setTimeout("fadeIn()", 1);
	}
}

//主要改动..把alpha的设置变成一个函数
function SetAlpha(poplayer, alpha) {
	if (alpha == 0) {
		poplayer.style.visibility = "hidden";
	}
	if (window.navigator.userAgent.indexOf("MSIE") >= 1) {
		poplayer.style.opacity = alpha;
	} else {
		poplayer.style.MozOpacity = alpha / 100;
	}
	alphanow = alpha;
}
if (!document.onmouseover) document.onmouseover = function (e) { if (!e) showPopupText(window.event); else showPopupText(e); };

function CheckAll(form) {
	for (var i = 0; i < form.elements.length; i++) {
		var e = form.elements[i];
		if (e.name != 'chkall') e.checked = form.chkall.checked;
	}
}

function CheckAll(form) {
	for (var i = 0; i < form.elements.length; i++) {
		var e = form.elements[i];
		if (e.name != 'chkall' && e.name != 'action') e.checked = form.chkall.checked;
	}
}

//下拉菜单相关代码
var h;
var w;
var l;
var t;
var topMar = 1;
var leftMar = -2;
var space = 1;
var isvisible;
var delayhide;
var MENU_SHADOW_COLOR = '#999999';//定义下拉菜单阴影色
var global = window.document
global.fo_currentMenu = null
global.fo_shadows = new Array

function DelayHideMenu() {
	var el = $('boardQueryLink2');
	if (el) { el.removeEvent('click') };
	delayhide = setTimeout("HideMenu()", 100);
}

function ClearHideMenu() {
	if (delayhide) {
		clearTimeout(delayhide);
	}
}

function HideMenu() {
	vDiv = document.getElementById("menuDiv");
	//vDiv.style.visibility = "hidden";
	vDiv.style.display = "none";
}

function ShowMenu(ele, vMnuCode, tWidth) {
	ClearHideMenu();
	vSrc = ele;
	vMnuCode = "<table id='submenu' cellspacing=1 cellpadding=3 style='width:" + tWidth + "' onmouseover='ClearHideMenu();' onmouseout='DelayHideMenu();' class=tableborder1 ><tr height=23><td nowrap align=left class=tablebody1>" + vMnuCode + "</td></tr></table>";

	h = vSrc.offsetHeight;
	w = vSrc.offsetWidth;
	l = vSrc.offsetLeft + leftMar + 4;
	t = vSrc.offsetTop + topMar + h + space - 2;
	vParent = vSrc.offsetParent;
	while (vParent.tagName.toUpperCase() != "BODY") {
		l += vParent.offsetLeft;
		t += vParent.offsetTop;
		vParent = vParent.offsetParent;
	}
	vDiv = document.getElementById("menuDiv");
	vDiv.innerHTML = vMnuCode;
	vDiv.style.top = t;
	vDiv.style.left = l;
	//vDiv.style.visibility = "visible";
	vDiv.style.display = "block";
	if (Browser.Engine.trident) { makeRectangularDropShadow(submenu, MENU_SHADOW_COLOR, 4) };
	var el = $('boardQueryLink2');
	if (el) { el.addEvent('click', boardQuery) };
}

function makeRectangularDropShadow(el, color, size) {
	var i;
	for (i = size; i > 0; i--) {
		var rect = document.createElement('div');
		var rs = rect.style
		rs.position = 'absolute';
		rs.left = (el.style.posLeft + i) + 'px';
		rs.top = (el.style.posTop + i) + 'px';
		rs.width = el.offsetWidth + 'px';
		rs.height = el.offsetHeight + 'px';
		rs.zIndex = el.style.zIndex - i;
		rs.backgroundColor = color;
		var opacity = 1 - i / (i + 1);
		rs.filter = 'alpha(opacity=' + (100 * opacity) + ')';
		el.insertAdjacentElement('afterEnd', rect);
		global.fo_shadows[global.fo_shadows.length] = rect;
	}
}

function movecursor() {
	range = document.frmAnnounce.Content.createTextRange();
	range.collapse(false);
	range.moveEnd('character', 0);
	range.select();
}