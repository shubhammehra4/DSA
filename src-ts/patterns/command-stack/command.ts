type CommandFunction<State> = (state: State) => [State, (state: State) => State];

const createCommandStack = <State>(intialState: State) => {
  const stack: ((state: State) => State)[] = [];
  let state = intialState;

  return {
    excecute(command: CommandFunction<State>) {
      const [newState, undoFunc] = command(state);
      state = newState;
      stack.push(undoFunc);
      return state;
    },
    undo() {
      const command = stack.pop();
      if (command) {
        state = command(state);
      }

      return state;
    },
  };
};

const addOne: CommandFunction<number> = (state) => [state + 1, (st) => st - 1];

const cStack = createCommandStack<number>(0);

console.log(cStack.excecute(addOne));
console.log(cStack.undo);
