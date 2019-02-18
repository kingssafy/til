//const f1 = function() { return "hello!"; };
//Arrow functions do have one major difference
//from regular functions;
//`this` is bound lexically. just like any other
//variable

const o = {
  name: 'Julie',
  greetBackwards: function() {
    const getReverseName = () => {
      let nameBackwards = '';
      for(let i=this.name.length-1; i>=0; i--) {
        nameBackwards += this.name[i];
      }
      return nameBackwards;
    };
    return `${getReverseName()} si eman my ,olleH`;
  },
};
console.log(o.greetBackwards());
