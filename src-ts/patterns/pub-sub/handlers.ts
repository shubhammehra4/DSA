const createHandlerStack = <MessageType>() => {
  const subscribers: Set<(msg: MessageType) => undefined | unknown> = new Set();

  const subscribe = (cb: (msg: MessageType) => undefined | unknown): (() => void) => {
    subscribers.add(cb);
    return () => {
      subscribers.delete(cb);
    };
  };

  const publish = (msg: MessageType): undefined | unknown => {
    let data: unknown;
    for (const subscriber of subscribers) {
      data = subscriber(msg);

      if (data !== undefined) break;
    }

    return data;
  };

  return { subscribe, publish };
};
