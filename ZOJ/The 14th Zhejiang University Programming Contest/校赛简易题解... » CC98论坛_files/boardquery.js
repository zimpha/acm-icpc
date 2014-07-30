var sel = -1;
var json = '';

function showSwl(obj) {
    if (!$("resultBox")) {
		new Element('div',{
			id:'resultBox',
			styles:{
				'background-color':'#fff',
				'overflow':'auto',
				'z-index':9999,
				'min-width':obj.getSize().x.toString() + 'px'
			}
		}).injectAfter(obj);
    }
	$("resultBox").setStyle('display','');
    var targetDiv = $("resultItem");
    targetDiv.empty();
	targetDiv.setStyle('height','');
	$each(json,function(item){
		new Element('div',{
			html:item.boardname + '<br />&nbsp;&nbsp;<span style="color:#999; overflow:hidden">' + item.readme.substr(0,50) + '....</span>',
			id:'sel_'+item.boardid,
			styles:{cursor:"pointer"}
		}).inject(targetDiv,'bottom').addClass('item').addEvents({
			'mouseenter':function(){
				this.setStyle('background-color', '#E9EEF6');
			},
			'mouseleave':function(){
				this.setStyle('background-color', '#fff');
			},
			'click':function(){
				ccdialog.close({'opt':'q','fn':function(){
					window.location.href = "list.asp?boardid=" + this.id.substr(4,this.id.length);
				}.bind(this)});
			}
		});
	})
	if(targetDiv.getSize().y > 300){
		targetDiv.setStyle('height','300px');	
	}

}

function getSel(kc, obj) {
	var els = obj.getChildren();
	var fxSc = new Fx.Scroll(obj, {duration: 'short'});
	if(kc == 40){
		if (sel > -1){els[sel].setStyle('background-color', '#fff');};
		if(sel == els.length - 1){
			sel = 0;
			fxSc.options.duration = 1000;
			fxSc.toTop();
		}else{
			sel ++;
			if(els[sel].getPosition(obj).y > (obj.getSize().y/2 + 50)){fxSc.start(0,obj.getScroll().y+31);}
		};
		els[sel].setStyle('background-color', '#E9EEF6');
	}else if(kc == 38){
		if (sel < els.length && sel != -1){els[sel].setStyle('background-color', '#fff');};
		if(sel == 0){
			sel = els.length - 1;
			fxSc.options.duration = 1000;
			fxSc.toBottom();
		}else{
			sel --;
			if(els[sel].getPosition(obj).y < (obj.getSize().y/2 - 50)){fxSc.start(0,obj.getScroll().y-31);}
		}
		els[sel].setStyle('background-color', '#E9EEF6');
	}
}

function showdiv(objid, e) {
	if (!$(objid)){
		return ;
	}
	var obj = $(objid);
    if (obj.value != '') {
        if (e.code != 38 && e.code != 40 && e.code != 13) {
			sel = -1;
			var jsonRequest = new Request.JSON({
				url: "queryboard.asp",
				onComplete: function(res,text){
					if (res != null && res.length >0){
						json = res;
						showSwl(obj);
					}else if($("resultBox")){
						$("resultBox").setStyle('display','none');
					}
				}
			}).send('k='+encodeURI(obj.value));
       	} else if (e.code == 13) {
            if (json.length > sel && sel > -1) {
				ccdialog.close({'opt':'q','fn':function(){
					window.location.href = "list.asp?boardid=" + json[sel].boardid;
				}});
            }else if (json.length == 1) {
				ccdialog.close({'opt':'q','fn':function(){
					window.location.href = "list.asp?boardid=" + json[0].boardid;
				}});
            }
        } else if($("resultBox")){
			getSel(e.code, $("resultItem"));
        }
    }
    else {
        if ($("resultBox")) {
            $("resultBox").setStyle('display','none');
        }
    }
}