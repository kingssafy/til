// Expressions and control flow patterns
//
//
// Converting if..else statements to conditional statements
if(isPrime(n)) {
  label = 'prime';
} else {
  label = 'non-prime';
}
//would be better written as
label = isPrime(n) ? 'prime' : 'non-prime';




