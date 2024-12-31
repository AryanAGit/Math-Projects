const mainCanvas = document.getElementById('mainCanvas');
const mainCtx = mainCanvas.getContext('2d');
const lineCanvas = document.getElementById('lineCanvas');
const lineCtx = lineCanvas.getContext('2d');

const centerX = mainCanvas.width / 2; // Center x
const centerY = mainCanvas.height / 2; // Center y
const length = 100; // Length of the line
t = 0; // Initial angle

dt = 0.001;
let set = [];
const scale = 20;

stopper = false;

set.push([12.5,-6.28319, 1.5708]);
set.push([3,-18.8496, 4.71239]);
set.push([2.5,-12.5664, 4.71239]);
set.push([2.5,12.5664, -1.5708]);
set.push([1,18.8496 , 1.5708]);
set.push([0.5,-25.1327, 4.71239]);
set.push([0.5,6.28319, 1.5708]);
set.push([0.5,25.1327,  -1.5708]);

/*

set.push([12.5,-6.28319, 1.5708]);
set.push([0.5,6.28319, 1.5708]);
set.push([2.5,12.5664, -1.5708]);
set.push([2.5,-12.5664, 4.71239]);
set.push([3,-18.8496, 4.71239]);
set.push([1,18.8496 , 1.5708]);
set.push([0.5,25.1327,  -1.5708]);
set.push([0.5,-25.1327, 4.71239]);
*/
/*
set.push([0.5,25.1327,  -1.5708]);
set.push([0.5,6.28319, 1.5708]);
set.push([0.5,-25.1327, 4.71239]);
set.push([1,18.8496 , 1.5708]);
set.push([2.5,12.5664, -1.5708]);
set.push([2.5,-12.5664, 4.71239]);
set.push([3,-18.8496, 4.71239]);
set.push([12.5,-6.28319, 1.5708]);
*/
//set.push([20,2*Math.PI,  0]);
//set.push([10,4*Math.PI,  0.5*Math.PI]);
//set.push([40,0.5*Math.PI,  Math.PI]);


// Function to calculate the x and y positions
/*
function calculateLineEndPoint(x, y, r, phi, theta) {
    xNew = x + r*Math.cos(phi*t+theta);
    yNew = y + r*Math.sin(phi*t+theta);
    return { xNew, yNew }; 
}
*/
function drawRotatingLine() {
    lineCtx.clearRect(0, 0, lineCanvas.width, lineCanvas.height);
    lineCtx.beginPath();
    lineCtx.moveTo(centerX, centerY);
    x = centerX;
    y = centerY;
   
    for( let i = 0; i< set.length; i++){
        
        //lineCtx.moveTo(x, y);
        x += scale*set[i][0]*Math.cos(t*set[i][1]+set[i][2]);
        y -= scale*set[i][0]*Math.sin(t*set[i][1]+set[i][2]);
        /*
        console.log(i)
        console.log(set[i][0]);
        console.log(set[i][1]);
        console.log(set[i][2]);
        console.log(set[i][0]*Math.cos(t*set[i][1]+set[i][2]));
        console.log(set[i][0]*Math.sin(t*set[i][1]+set[i][2]));
        console.log("\n\n\n")
        */
        //x = centerX+100*Math.cos(2*Math.PI*t);
        //y = centerY + 100*Math.sin(2*Math.PI*t);
        //hue = 360*t;
        //lineCtx.strokeStyle = `hsl(${hue}, 100%, 30%)`;
        lineCtx.strokeStyle = 'rgba(0, 72, 85, 1)'; // Line color

        lineCtx.lineTo(x, y); // Ending point
        lineCtx.lineWidth = 1; // Line width
        lineCtx.stroke();
    
        
     }
    mainCtx.fillStyle = 'rgb(153, 0, 0)'; // Color of the pixel
    mainCtx.fillRect(x, y, 2, 2); // Draw each dot
    if(t>=1 && stopper){
      ;
    } // Request next frame
    else{
        t += dt
        requestAnimationFrame(drawRotatingLine);
    }
    
}

// Start the animation
drawRotatingLine();
