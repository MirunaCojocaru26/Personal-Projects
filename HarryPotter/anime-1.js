
window.onload=function()
{
	var d3=document.querySelector("body");
	var b=document.getElementById("magic");
	d3.onmousemove=function(e)
	{
		b.style.left=e.pageX+1+"px";
		b.style.top=e.pageY+1+"px";
		this.style.backgroundColor="#99ccff";
	}
var x=document.getElementById("one");
x.onclick=doi;
}
function unu()
{
var x=document.getElementById("one");
x.src="pag2-photo1.jpg";
x.onclick=doi;
}
function doi()
{
var x=document.getElementById("one");
x.src="pag2-photo4.jpg";
x.onclick=trei;
}
function trei()
{
var x=document.getElementById("one");
x.src="pag2-photo2.jpg";
x.onclick=patru;
}
function patru()
{
var x=document.getElementById("one");
x.src="pag2-photo3.jpg";
x.onclick=cinci;
}
function cinci()
{
var x=document.getElementById("one");
x.src="pag2-photo5.jpg";
x.onclick=unu;
}