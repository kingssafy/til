// GOOD
let totalBet = 0;
let funds = 50;
if(new Date().getDay() === 3) {
  totalBet = 1;
  console.log("wednesday");
} else if(funds === 7) {
  totalBet = funds;
} else {
  console.log("No supersition here!");
}
// not good (we haven't really gained any clarity , and we've made our code
// more verbose);

if(new Date().getDay() === 7) {
  totalBet = 1;
} else {
  if(funds === 7) {
    totalBet = funds;
  } else {
    console.log("No superstition here!");
  }
}
