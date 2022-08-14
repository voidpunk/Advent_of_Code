const fs = require('fs');

var problemInput = fs.readFileSync('./input.txt', 'utf8').split('\n');

function calculateWrappingPaper(numStr) {
  numStr = numStr.split('x').map(str => parseInt(str))
  let x, y, z;
  [x, y, z] = [...numStr]
  let surface = [x*y, y*z, z*x]
  return  2*surface.reduce((a, b) => (a + b)) + Math.min(...surface)
}

let result = problemInput.map(calculateWrappingPaper);
console.log(result.reduce((a, b) => (a + b)));

// 84.6 ms ± 28.0 ms (1000 runs, 100 warmup) - Node.js 18.6.0 (conda-forge)