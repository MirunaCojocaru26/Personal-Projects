window.onload=function()
{
	var x=document.getElementById("butonulmagic");
	x.onclick=prea_multe_raspunsuri;
}
function prea_multe_raspunsuri()
{
		var x=document.querySelector("#tot input:nth-of-type(2)");
		var y=document.querySelector("#tot input:nth-of-type(6)");
		var z=document.querySelector("#tot input:nth-of-type(7)");
		var w=document.querySelector("#tot input:nth-of-type(10)");
		var q=document.querySelector("#tot input:nth-of-type(14)");
		var nr=0;
		if(x.checked==true)nr++;
		if(y.checked==true)nr++;
		if(z.checked==true)nr++;
		if(w.checked==true)nr++;
		if(q.checked==true)nr++;
		var nr2=5-nr;
		if(nr==5)
		{
	
			var t=1;
			if(localStorage.lastOpen==undefined)
			{
				f=open("https://www.youtube.com/watch?v=SC4xMk98Pdc");
				localStorage.locatie=f.URL;
				d= new Date();
				localStorage.lastOpen=d;
			}
			else
			{
				if(localStorage.lastOpen!=t)
					{
						localStorage.lastOpen=t;
					}
				//localStorage.clear();
			}
		}
		else alert("Ai " + nr + " raspunsuri corecte si " + nr2 + " raspunsuri gresite");
}