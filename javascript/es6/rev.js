// returns a random integer in the range [m. n] exclusive
function rand(m, n) {
  return m + Math.floor((n - m + 1)*Math.random());
}

// randomly returns a string representing one of six
// Crown and Anchor Faces
function randFace() {
  return ["crown", "anchor", "spade", "heart", 
    "club", "diamond"][rand(0,5)];
}

let funds = 50;
let round = 0;

while(funds > 0 && funds < 100) {
  round++;
  console.log(`round ${round}:`);
  console.log(`\tstarting funds: ${funds}p`);
  //place bets
  let bets = { crown: 0, anchor: 0, spade: 0,
               heart: 0, club: 0, diamond: 0,
  };
  let totalBet = rand(1, funds);
  if(totalBet === 7) {
    totalBet = funds;
    bets.heart = totalBet;
  } else {
    let remaining = totalBet;
    do{
      let bet = rand(1, remaining);
      bets[randFace()] += bet;
      remaining -= bet;
    } while(remaining > 0)
  }
  funds -= totalBet;
  console.log('\tbets: ' +
    Object.keys(bets).map(face => `${face}: ${bets[face]} pence`).join(', ') +
    ` (total: ${totalBet} pence)`);
  
  // roll dice
  const hand = [];
  for(let roll = 0; roll < 3; roll++) {
    hand.push(randFace());
  }
  console.log(`\thand: ${hand.join(', ')}`);

  //collect winnings
  let winnings = 0;
  for(let die = 0; die < hand.length; die++) {
    let face = hand[die];
    if(bets[face] > 0) winnings += bets[face];
  }
  funds = funds + winnings;
  console.log(`\twinnings: ${winnings}`);
}
console.log(`\tending funds: ${funds}`);
