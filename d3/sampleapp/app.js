window.addEventListener("load", function() {
  console.log("Hello World!");
});

function shuffleCx(){
  var canvas = d3.select("svg");
  var circle = canvas.selectAll("circle");
  circle.attr("cx", function(){return Math.random() * 720;});
  circle.style("fill", "red");
  circle.style("stroke", "#222");

}


function generate(){
  console.log("in generate");
  var canvas = d3.select("svg");
  var circles = canvas.selectAll("rect").data([33,66,88, 55, 68, 200]);
  console.log(circleEnter)
  var circleEnter = circles.enter().append("rect");
  circleEnter.attr("y", 60);
  circleEnter.attr("x", function(d,i){return d });
  circleEnter.attr("width", function (d) { return Math.sqrt(d);  });
  circleEnter.attr("height", function (d) { return Math.sqrt(d);  });
  circleEnter.attr("height", function (d) { return Math.sqrt(d);  });

}
// let has block scope
// var function scope
// foreach loops cannto be interrumped
/** creates the object array and fills the x,y,w,h,color */
function generateGrid(n,m,w) {
  // the fat arrow by default does not returns objects, in this case 
  // it's necessary to explicitly add the return keyword
  // or it will be interpreted as a scope and not and object
  var arr = new Array(n).fill().map( (v,i) => {
      return Array(m).fill().map((v,ii) => { return {x:ii*w, y:i*w, w:w, color:"gray" }})
    })
  return arr;
}

function draw_grid() {
  console.log("draw grid");
  var n = parseInt(document.getElementById("grid_n").value);
  var m = parseInt(document.getElementById("grid_m").value);
  var w = parseInt(document.getElementById("grid_w").value);

  var data = generateGrid(n,m,w);
  console.log(data);
  var grid = d3.select("#grid")
               .append("svg")
               .attr("width", (w*m)+"px")
               .attr("height", (w*n)+"px");

  var row = grid.selectAll(".row")
                .data(data)
                .enter().append("g")
                .attr("class", "row")
  
  var col = row.selectAll(".sq")
               .data(function(d){return d;})
               .enter().append("rect")
               .attr("class", "sq")
               .attr("x", (d) => d.x)
               .attr("y", (d) => d.y)
               .attr("width", (d) => d.w)
               .attr("height", (d) => d.w)
               .style("fill", (d)=>d.color)
               .style("stroke", "#222")
               .on("click", (d)=>{
                 console.log(d.x);
               })
                
}

function blurMe(){
  console.log("blurr")
}