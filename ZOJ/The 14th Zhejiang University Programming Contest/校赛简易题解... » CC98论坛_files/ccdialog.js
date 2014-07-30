//cc98 Dialog box version 1.0
//author:绝对小孩
//@2009.4.30

var searchBox = '<div style="width:520px;"><div class="x-box-tl"><div class="x-box-tr"><div class="x-box-tc"></div></div></div><div class="x-box-ml"><div class="x-box-mr"><div class="x-box-mc"><h3 style="margin-bottom:5px;">论坛板块搜索</h3><span id="inputWrap" class="x-form-field-wrap" style="width: 490px;"></span><div style="padding-top:4px;">请输入你希望搜索的关键字,系统将自动搜索!(点击周围空白处即可关闭该窗口)</div></div></div></div><div class="x-box-bl"><div class="x-box-br"><div class="x-box-bc"></div></div></div></div>';
var resultBoxHtml = '<div id="resultItem"><div class="item"></div></div><div id="resultTitle"><span style="margin-left:5px; padding-top:20px;">请使用上下方向键选择,Enter进入相应版块.或使用鼠标点击.</span></div>';
var ccdialog = new Class({
	Implements:[Options],
	options:{
		title:'Infomation Dialog',
		width:300,
		height:200,
		maskStyle:{bgColor:'#7f7f7f',opacity:0.6},
		boxStyle:{bgColor:'#fff',opacity:1},
		type:1,
		url:'about:blank',
		source:'<div id="blank" style="color:red;">Nothing to display!</div>',
		mP:{x:100,y:50}
	},
	initialize:function(options){
		this.setOptions(options);
	},
	open:function(){
		var maskLayer = new Element('div', {
			'id':'maskLayer',
			'styles': {
				'height':window.getScrollSize().y,
				'width':window.getScrollSize().x,
				'opacity':this.options.maskStyle.opacity
			}
		})
		
		maskLayer.inject(document.body).addClass('maskLayer').addEvent('click',function(){this.close();}.bind(this));	
		if(!$('s-box')){
			new Element('div',{id:'s-box',styles:{'opacity':0.5}}).inject(maskLayer,'after');
		}	
		var dialogBox = new Element('div', {
			'id':'dialogBox',
			'html':searchBox,
			'styles': {
				'left': (window.getSize().x - 520)/2 ,
				'top':(window.getSize().y - 300)/2
			}
		})
		var searchIn = new Element('input',{
			id:'searchIn',
			type:'text',
			size:40,
			autocomplete:'off',
			styles:{'width':'492px'}
		}).addClass('x-form-text x-form-field').addEvents({
			'keyup':function(e){
				showdiv('searchIn',e);
			},
			'blur':function(){
				this.removeClass('x-form-focus');
			},
			'focus':function(){
				this.addClass('x-form-focus');
			}
		})		
		var diaFx = new Fx.Morph('s-box',{duration: 'normal', transition: Fx.Transitions.Sine.easeOut})
		diaFx.set({
			top:this.options.mP.y + 'px',
			left:this.options.mP.x + 'px'
		})
		$('s-box').store('origPosition',this.options.mP);
		diaFx.start({
			'height': 100,
			'width': 520,
			'top': (window.getSize().y - 300 )/2 + 'px',
			'left': (window.getSize().x - 520 )/2 + 'px'
		}).addEvent('complete',function(){
			dialogBox.inject(maskLayer,'after');
			searchIn.inject('inputWrap');
			new Element('div',{id:'resultBox',html:resultBoxHtml,
				styles:{
					top:$('inputWrap').getCoordinates().bottom,
					left:$('inputWrap').getCoordinates().left,
					width:$('inputWrap').getSize().x
				}
			}).inject(document.body).setStyle('display','none');
			searchIn.focus();
		});
	},
	close:function(o){
		var ori = $('s-box').retrieve('origPosition');
		$('dialogBox').destroy();
		$('resultBox').destroy();
		var diaFxin = new Fx.Morph('s-box',{duration: (o&&o.opt)&&(o.opt=='q') ? 'short':'normal', transition: Fx.Transitions.Sine.easeOut})
		diaFxin.start({
			'height': 1,
			'width': 1,
			'top': ori.y + 'px',
			'left': ori.x + 'px'
		}).addEvent('complete',function(){
			$('maskLayer').destroy();
			if(o&&o.fn){
				o.fn();
			}
			$('s-box').destroy();
		});
	}
});
ccdialog.open = function(o){
	if($('maskLayer')) return
	return new ccdialog(o).open();
};
ccdialog.close = function(o){
	return new ccdialog().close(o);
};

window.addEvent('domready',function(){
	$$('#boardQueryLink').each(function(item){
		item.addEvent('click',boardQuery);
	})
})

var boardQuery = function(e){
	var mp = this.getPosition();
	ccdialog.open({mP:mp,height:100,width:520});
}