const fs = require('fs')

const problem_input = fs.readFileSync('./input.txt', 'utf8');
const open_parentheses = problem_input.match(/\(/g).length;
const closed_parentheses = problem_input.match(/\)/g).length;
const difference = open_parentheses - closed_parentheses;

console.log(difference);
