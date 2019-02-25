// Helper Functions

// returns a random integer in the range [m, n] (inclusive)
function rand(m, n) {
  return m + Math.floor((n - m +1)*Math.random());
}

// randomly returns a string representing one of the six
// Crown and Anchor faces
function randFace() {
  return ["crown", "anchor", "heart", "spade", "club", "diamond"]
    [rand(0, 5)];
}
// End Helper Functions

let funds = 50;
const bets = {'crown': 0, 'anchor': 0,  'heart': 0,
              'spade': 0, 'club': 0, 'diamond': 0,
}

let totalBet = rand(1, 50);
if(totalBet === 7) {
  totalBet = funds;
  bets.heart = totalBet;
} else {
  // distribute total bet
  let remaining = totalBet;
  let bet, face
  do{
    bet = rand(1, remaining);
    face = randFace();
    bets[face] = bets[face] + bet;
    remaining = remaining - bet;
  } while(remaining > 0);
}
funds = funds - totalBet;

const hand = []; // array
for(let roll = 0; roll < 3; roll++) {
  hand.push(randFace())
}

let winnings = 0;
for(let die=0; die < hand.length; die++) {
  let face = hand[die];
  if(bets[face] > 0) winnings = winnings + bets[face];
}
funds = funds + winnings;
