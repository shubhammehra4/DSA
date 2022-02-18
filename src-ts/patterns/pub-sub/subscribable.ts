const createSubscribable = <MessageType>() => {
  const subscribers: Set<(msg: MessageType) => void> = new Set();

  const subscribe = (cb: (msg: MessageType) => void): (() => void) => {
    subscribers.add(cb);
    return () => {
      subscribers.delete(cb);
    };
  };

  const publish = (msg: MessageType): void => {
    subscribers.forEach((cb) => cb(msg));
  };

  return { subscribe, publish };
};
