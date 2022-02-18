type MementoCommandFunction<State> = (state: State) => State;

const createMementoStack = <State>(intialState: State) => {
  const stack: string[] = [JSON.stringify(intialState)];

  return {
    excecute(command: MementoCommandFunction<State>) {
      const currentState = stack.at(-1);

      const newState = command(currentState !== undefined ? JSON.parse(currentState) : intialState);
      stack.push(JSON.stringify(newState));
      return newState;
    },
    undo() {
      if (stack.length > 1) stack.pop();

      const prevState = stack.at(-1);
      return prevState !== undefined ? JSON.parse(prevState) : intialState;
    },
  };
};

const addOneMem: MementoCommandFunction<number> = (state) => state + 1;

const mStack = createMementoStack<number>(0);

console.log(mStack.excecute(addOneMem));
console.log(mStack.undo());
