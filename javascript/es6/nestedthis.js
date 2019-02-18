//const o = {
//  name: 'Julie',
//  greetBackwards: function() {
//    function getReversedName() {
//      let nameBackwards = '';
//      for(let i=this.name.length-1; i>=0; i--) {
//        nameBackwards += this.name[i];
//      }
//      return nameBackwards;
//    }
//    return `${getReversedName()} si eman ym ,olleH`;
//  },
//};
//console.log(o.greetBackwards());


const o = {
  name: 'Julie',
  greetBackwards: function() {
    const self = this;
    function getReversedName() {
      let nameBackwards = '';
      for(let i=self.name.length-1; i>=0; i--) {
        nameBackwards += self.name[i];
      }
      return nameBackwards;
    }
    return `${getReversedName()} si eman ym ,olleH`
  },
};
console.log(
  o.greetBackwards()
);
