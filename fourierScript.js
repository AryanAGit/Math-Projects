const canvas = document.getElementById('drawingCanvas');
const ctx = canvas.getContext('2d');
const lineCanvas = document.getElementById('lineCanvas');
const lineCtx = lineCanvas.getContext('2d');
let drawing = false;
let drawn = false;
let out = false;
let startFourier = false;
const fourierBound =50;
let points = []; // Array to store the coordinates
let pointsN = [];
let circles = [];
t = 0;
dt = 0.0005;
scale = 100;
const oX = canvas.width / 2;
const oY = canvas.height / 2;
// Start drawing

class Complex{
    constructor(r, i){
        this.r =r;
        this.i = i;
        
    }
    mod(){
        return Math.sqrt(this.r*this.r +this.i*this.i);
    }
    theta(){
        if (this.i == 0 && this.r == 0) return 0;
        else if (this.r == 0 && this.i > 0) return Math.PI/2;
        else if (this.r == 0 && this.i < 0) return -0.5*Math.PI;
        else{
            let t = Math.atan(this.i/this.r);
            if(this.r < 0) t += Math.PI;
            return t;
        }
    }
}

function multiply(z, c){
    return new Complex(z.r*c.r-z.i*c.i, z.r*c.i+z.i*c.r);
}
canvas.addEventListener('mousedown', (event) => {
    drawing = true;
    ctx.beginPath(); // Start a new path
    ctx.moveTo(event.offsetX, event.offsetY); // Move to the click position
});

// Draw on the canvas
canvas.addEventListener('mousemove', (event) => {
    if (drawing && drawn == false) {
        const x = event.offsetX;
        const y = event.offsetY;
        lineCtx.lineTo(x, y); // Draw a line to the new position
        lineCtx.strokeStyle = 'black'; // Set line color to black
        lineCtx.lineWidth = 2; // Set line width
        lineCtx.stroke(); // Render the line
        xC = (x-oX)/100;
        yC = (oY-y)/100;
        // Store the coordinates
        points.push({ x, y });
        pointsN.push({xC, yC});
       
    }
});

// Stop drawing
canvas.addEventListener('mouseup', () => {
    drawing = false;
    drawn = true;
    if( out == false){
        console.log('Drawn points:', points);
        console.log('f(t) coords:', pointsN);
        out = true;
        Fourier();
    }
   
});

// Stop drawing when mouse leaves the canvas
canvas.addEventListener('mouseleave', () => {
    drawing = false;
    drawn = true;
    if( out == false){
        console.log('Drawn points:', points);
        console.log('f(t) coords:', pointsN);
        out = true;
        Fourier();
    }

});

function integrate(n){
    let I = new Complex(0, 0);
    let bound = pointsN.length;
    for(let i = 0; i < bound; i++){
        let temp = integrand(n, i);
        temp.r /= bound;
        temp.i /=  bound;
        I.r += temp.r;
        I.i += temp.i;
    }
  
    return I;
}
function integrand(n, t){
    let p = pointsN[t];
    //console.log(p);
    let ft = new Complex(p.xC, p.yC);
    let e = new Complex (Math.cos(2*Math.PI*n*t/pointsN.length), -Math.sin(2*Math.PI*n*t/pointsN.length));
    return multiply(ft, e);
}
function Fourier(){
   for( let i = 0; i< 2*fourierBound + 1; i++){
        //console.log(i);
        let n = i-fourierBound;
        //console.log(n);
        // Integration function doesnt work
        let Cn = integrate(n);
       // console.log(Cn);
        if(Cn.mod()>0.00001) circles.push([Cn.mod(), 2*Math.PI*n, Cn.theta()]);
   }

   console.log(circles);
   circles.sort((a, b) => b[0] - a[0]);
   console.log(circles);
   //ctx.clearRect(0, 0, canvas.width, canvas.height);
   drawRotatingLine();
}

function drawRotatingLine() {
    ctx.clearRect(0, 0, lineCanvas.width, lineCanvas.height);
    ctx.beginPath();
    ctx.moveTo(oX, oY);
    let x = oX;
    let y = oY;
   
    for( let i = 0; i< circles.length; i++){
        
      
        x += scale*circles[i][0]*Math.cos(t*circles[i][1]+circles[i][2]);
        y -= scale*circles[i][0]*Math.sin(t*circles[i][1]+circles[i][2]);
   
        //hue = 360*t;
        //lineCtx.strokeStyle = `hsl(${hue}, 100%, 30%)`;
        ctx.strokeStyle = 'rgba(0, 72, 85, 1)'; // Line color

        ctx.lineTo(x, y); // Ending point
        ctx.lineWidth = 2; // Line width
        ctx.stroke();
    
        
     }
    lineCtx.fillStyle = 'rgb(153, 0, 0)'; // Color of the pixel
    lineCtx.fillRect(x, y, 4,4); // Draw each dot
   // Request next frame
    
    t += dt;
    requestAnimationFrame(drawRotatingLine);

    
}


