/* eslint-disable no-use-before-define */
class GraphNode {
  val: number;

  neighbors: GraphNode[];

  constructor(val?: number, neighbors?: GraphNode[]) {
    this.val = val === undefined ? 0 : val;
    this.neighbors = neighbors === undefined ? [] : neighbors;
  }
}

function cloneGraph(src: GraphNode | null): GraphNode | null {
  if (src == null) return null;

  const map: { [key: number]: GraphNode } = {};

  const traverse = (node: GraphNode): GraphNode => {
    if (map[node.val] === undefined) {
      map[node.val] = new GraphNode(node.val, []);
      map[node.val].neighbors = node.neighbors.map(traverse);
    }

    return map[node.val];
  };

  return traverse(src);
}
