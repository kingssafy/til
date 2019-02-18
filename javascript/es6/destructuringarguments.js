function getSentence({ subject, verb, object }) {
  return `${subject} ${verb} ${object}`;
}

const o = {
  subject: "I",
  verb: "love",
  object: "JavaScript",
  aux: "auxilary",
};

console.log(getSentence(o));


function getSentenceS([ subject, verb, object ]) {
  return `${subject} ${verb} ${object}`;
}

const arr = [ "I", "may love", "Javascript" ];
console.log(getSentenceS(arr));

function addPrefix(prefix, ...words) {
  // we will learn a better way to do this later!
  const prefixedWords = [];
  for(let i=0; i<words.length; i++) {
    prefixedWords[i] = prefix + words[i];
  }
  return (arguments);
}
console.log(addPrefix("con", "verse", "vex", "vention"));
