function randInt(m, n) {
  return m + Math.floor((n - m + 1) * Math.random());
}

for(let i=0; i<100; i++) {
  let totalBet = randInt(1,50);
  switch(totalBet) {
    case 7:
      totalBet = 50;
      console.log("case 7");
      break;
    case 13:
      totalBet = 0;
      console.log("case 13");
    case 11:
      totalBet = 0;
      console.log("case 11");
      break;
    case 21:
      totalBet = 21;
      console.log("case 21");
      break;
    default:  //it's conventional (but not required) to put the default case last
      console.log("No supersition here!");
      break; // break is unnecessary because no cases follow `default`. but 
             // always providing a `break` statement is good habit to get in to
  }
}

console.log(i)

switch(totalBet) {
  case 7: totalBet = funds; break;
  case 11: totalBet = 0; break;
  case 13: totalBet = 0; break;
  case 21: totalBet = 21; break;
}
