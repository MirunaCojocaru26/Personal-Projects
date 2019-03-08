window.onload=function()
{
	var fulguleti=setInterval(Multi,1000);
}
function Multi()
{
	var i=document.createElement("img");
	i.src="altreileafulg.png";
	var d=document.querySelector("div");
	i.xnou=100;
	i.style.top=i.xnou+"px";
	i.size=Math.floor(Math.random()*150+1);
	i.style.height=i.size+"px";
	i.style.width=i.size+"px";
	i.style.left=Math.floor(Math.random()*1000+1)+"px";
	i.t=setInterval(function(){i.xnou+=50; i.style.top=i.xnou+"px";},500);
	d.appendChild(i);	
}