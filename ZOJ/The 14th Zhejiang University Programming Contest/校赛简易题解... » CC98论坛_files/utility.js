//================utility.post.js===================//
//从common.js中分离出来，用于发表帖子相关的页面//
//author:绝对小孩
//date:2009.3
//updates:
//
// 2013.06.21 (樱桃): 权限账户锁定发帖检查

var _editMode = 0;
var userAgent = navigator.userAgent.toLowerCase();
var isOpera = userAgent.indexOf('opera') != -1 && opera.version();
var isMoz = (navigator.product == 'Gecko') && userAgent.substr(userAgent.indexOf('firefox') + 8, 3);
var isIE = (userAgent.indexOf('msie') != -1 && !isOpera) && userAgent.substr(userAgent.indexOf('msie') + 5, 3);
var canStoreData = isIE >= 5 || isMoz >= 2 ? 1 : 0;
var timeID;
var clTimeID;
var autoSaveInterval = 20;
var clInterval = 6;
var isWarming = false;
var appendCode = '<div id="contentState" style="height:20px; width:585px; margin-top:5px; border:none; text-align:right"><span id="autoSave" style="float:left; padding:3px 5px 3px 5px;"></span><span id="contentLength">0</span>&nbsp;字节&nbsp;<span id="saveContent" style="cursor:pointer;">&nbsp;|&nbsp;保存数据</span><span id="recover" style="cursor:pointer">&nbsp;|&nbsp;恢复数据</span></div>';

window.addEvents({
	'domready': function () {
		if (!canStoreData) {
			$('recover').style.display = 'none';
			$('saveContent').style.display = 'none';
			$('autoSave').style.display = 'none';
		} else {
			if (isIE >= 5)
				$('content').style.behavior = "url('#default#userData')";
		}
		timeID = autoSaveData.periodical(autoSaveInterval * 1000);
		clTimeID = checkContentLength.periodical(clInterval * 1000);
		$('saveContent').addEvent('click', function () {
			$clear(timeID);
			saveData($('content').value, 0);
			timeID = autoSaveData.periodical(autoSaveInterval * 1000);
		})

		$('recover').addEvent('click', function () {
			$clear(timeID);
			recoverData();
			timeID = autoSaveData.periodical(autoSaveInterval * 1000);
		});
	},
	'beforeunload': function () {
		if (!_editMode) {
			try {
				saveData($('content').value, 0);
			} catch (e) { }
		}
	}
})

var uploadImgFix = function () {
	if (!$defined($('content')))
		return false;
	var isUploadImgFix = $defined($('uploadImgFix')) ? $('uploadImgFix').checked : false
	if (isUploadImgFix) {
		var pattern = /\[upload=(gif|jpg|jpeg|bmp|png),1\](http:\/\/file\.cc98\.org\/.[^\[\'\"\:\(\)]*)(gif|jpg|jpeg|bmp|png)\[\/upload\]/gi;
		$('content').value = $('content').value.replace(pattern, '[upload=$1]$2$1[/upload]');
	}
}

function submitonce(theform) {
	uploadImgFix();
	//if IE 4+ or NS 6+
	if (document.all || document.getElementById) {
		//screen thru every element in the form, and hunt down "submit" and "reset"
		for (i = 0; i < theform.length; i++) {
			var tempobj = theform.elements[i];
			if (tempobj.type.toLowerCase() == "submit" || tempobj.type.toLowerCase() == "reset")
				//disable em
				tempobj.disabled = true;
		}
	}

	if (theform["locked"].value == "true") {
		if (confirm("该主题已经被锁定。您确认要在锁定的情况下进行回复吗？")) {
			return true;
		}
		else {
			for (i = 0; i < theform.length; i++) {
				var tempobj = theform.elements[i];
				if (tempobj.type.toLowerCase() == "submit" || tempobj.type.toLowerCase() == "reset")
					//disable em
					tempobj.disabled = false;
			}
			return false;
		}
	}
}


function ctlent(evt) {
	evt = evt ? evt : window.event;
	if (evt.keyCode == 13 && evt.ctrlKey) {
		this.document.frmAnnounce.Submit.click();
	}
}


//==================================================================
//	JLEEX Begin @ 10:59 PM 10/3/2008
//	 * Method for calling back from frame.
//	 * getEditContent() is a Call Back function for the editing content.
//     * insertsmile(smileface) is an override function, it's located in INC/ubbcode.js if I'm correct.

function getEditContent() {
	if (_editMode == 0) {
		return document.getElementsByName("Content")[0].innerHTML;
	}
	else {
		if (typeof (window.frames["Editor"].editdoc.body) == "undefined")
			return window.frames["Editor"].document.getElementById("posteditor_textarea").value;
		else
			return window.frames["Editor"].html2bbcode(window.frames["Editor"].editdoc.body.innerHTML);
	}
}

function insertsmilie(smilieface) {
	if (_editMode == 0) {
		document.frmAnnounce.Content.focus();
		try {
			document.selection.createRange().text += smilieface;
		}
		catch (ex) {
			document.frmAnnounce.Content.value += smilieface;
		}
	}
	else {
		if (window.frames["Editor"].wysiwyg == 0) {
			window.frames["Editor"].document.getElementById('posteditor_textarea').focus();
			try {
				window.frames["Editor"].document.selection.createRange().text += smilieface;
			}
			catch (ex) {
				window.frames["Editor"].document.getElementById('posteditor_textarea').value += smilieface;
			}
		}
		else {
			window.frames["Editor"].editdoc.body.focus();
			try {
				window.frames["Editor"].document.selection.createRange().text += smilieface;
			}
			catch (ex) {
				window.frames["Editor"].editdoc.body.innerHTML += smilieface;
			}
		}
	}
}

function switchEditMode() {
	if (_editMode == 0) {
		$clear(timeID);
		$clear(clTimeID);
		document.getElementById("SwitchEvent").innerHTML = "使用经典文本方式进行编辑";
		document.getElementById("EditArea").innerHTML = "<textarea name=\"Content\" style=\"display:none\" wrap=\"physical\">" + getEditContent() + "</textarea>\n<iframe ID=\"Editor\" name=\"Editor\" src=\"INC/UbbEditor/edit.html?ubb=1&id=Content\" frameBorder=\"0\" marginHeight=\"0\" marginWidth=\"0\" scrolling=\"No\" style=\"height:402px;width:100%\"></iframe>";
		_editMode = 1;
	}
	else {
		document.getElementById("SwitchEvent").innerHTML = "使用 UBB 编辑器进行编辑";
		document.getElementById("EditArea").innerHTML = "<textarea class=FormClass name=Content id=\"Content\" cols=95 wrap=VIRTUAL title=\"可以使用Ctrl+Enter直接提交帖子\" style=\"height:150px;\" onkeydown=\"ctlent(event)\" tabindex=\"3\"  onpropertychange=\"if(this.scrollHeight>150) this.style.posHeight=this.scrollHeight\">" + getEditContent() + "</textarea>" + appendCode;
		_editMode = 0;

		if (!canStoreData) {
			$('recover').style.display = 'none';
			$('saveContent').style.display = 'none';
			$('autoSave').style.display = 'none';
		}
		timeID = autoSaveData.periodical(autoSaveInterval * 1000);
		clTimeID = checkContentLength.periodical(clInterval * 1000);
	}
}

//============<!-- JLEEX End -->======================

function in_array(needle, haystack) {
	if (typeof needle == 'string' || typeof needle == 'number') {
		for (var i in haystack) {
			if (haystack[i] == needle) {
				return true;
			}
		}
	}
	return false;
}

function trim(str) {
	return (str + '').replace(/(\s+)$/g, '').replace(/^\s+/g, '');
}

var autoSaveData = function () {
	saveData($('content').value, 1);
}

function recoverData() {
	var message = '';
	if (isIE >= 5) {
		$('content').load('cc98bbsContent');
		message = $('content').getAttribute('bbsContent');
	} else if (window.sessionStorage) {
		try {
			message = sessionStorage.getItem('cc98bbsContent');
		} catch (e) { }
	}
	message = message.toString();
	if (in_array((message = trim(message)), ['', 'null', 'false', null, false])) {
		alert('没有可以恢复的数据！');
		return;
	}
	if (!confirm("此操作将覆盖当前帖子内容，确定要恢复数据吗？")) {
		return;
	}
	$('content').value = message;
}

var saveData = function (data, auto) {
	if (!data) {
		return;
	}
	if (isIE >= 5) {
		try {
			$('content').setAttribute("bbsContent", data);
			var oTimeNow = new Date();
			oTimeNow.setHours(oTimeNow.getHours() + 48);
			$('content').expires = oTimeNow.toUTCString();
			$('content').save('cc98bbsContent');
		} catch (e) {
		}
	} else if (window.sessionStorage) {
		try {
			sessionStorage.setItem('cc98bbsContent', data);
		} catch (e) {
		}
	}

	var date = new Date();
	var nowTime = date.getHours().toString() + ':' + date.getMinutes().toString() + ':' + date.getSeconds().toString();
	$('autoSave').innerHTML = auto == 1 ? '帖子内容自动保存于' + nowTime : '帖子内容保存于' + nowTime;

	var myEffect = new Fx.Morph('autoSave', { duration: 1500, transition: Fx.Transitions.Sine.easeOut });
	myEffect.start({ 'background-color': ['#e4e8ef', '#fff'] })
}

var checkContentLength = function () {
	var CL = strlen($('content').value);
	$('contentLength').innerHTML = CL.toString();
	if (parseInt(CL) > 16240) {
		if (!isWarming) alert('当前帖子长度为：' + parseInt(CL) + ';单贴长度不能超过16240字节,请适当处理，以免数据丢失！');
		isWarming = true;
	} else {
		isWarming = false;
	}
}