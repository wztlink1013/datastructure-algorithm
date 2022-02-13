/**
 *  @desc  单向链表
 */


class Node {  // 链表节点
  constructor(element) {
    this.element = element;
    this.next = null;   // 节点的指向下个节点的指针
  }
}


class NodeList {   //  链表
  constructor(item) {
    this.head = new Node(item);   //  初始化链表的头节点
  }
  /**
   * @description 插入元素
   * @param {需要插入的元素} newItem 
   * @param {插入到某一元素之后} beforeItem 
   */
  insertInNext(newItem, beforeItem) {
    let newNode = new Node(newItem);
    if (beforeItem) { //  判读是否是插入到指定节点后面，如果不是则插入到最后一个节点。
      let currNode = this.find(beforeItem);
      newNode.next = currNode.next;
      currNode.next = newNode;
    } else {
      let lastNode = this.findLastNode();
      lastNode.next = newNode;
    }
  }
  /**
   * @description 删除元素
   * @param {删除的元素} newItem 
   */
  remove(item) {
    let preNode = this.findPreNode(item);  //  找到前一节点，将前一节点的next指向该节点的next
    if (preNode.next != null) {
      preNode.next = preNode.next.next;
    }
  }
  /**
   * @description 查找元素的节点
   * @param {查找的元素} item 
   */
  find(item) { //  根据元素查找节点
    let currNode = this.head;
    while (currNode.element !== item && currNode) {
      if (currNode.next) {
        currNode = currNode.next;
      } else {
        currNode = null;
      }
    }
    return currNode;
  }
  /**
   * @description 查找最后一个节点
   */
  findLastNode() {
    let currNode = this.head;
    while (currNode.next) {
      currNode = currNode.next;
    }
    return currNode;
  }
  /**
   * @description 查找元素的前一节点
   * @param {查找的元素} item 
   */
  findPreNode(item) {
    let currNode = this.head;
    while (currNode && currNode.next && currNode.next.element !== item) {
      if (currNode.next) {
        currNode = currNode.next;
      } else {
        currNode = null;
      }
    }
    return currNode;
  }
  toString() {
    let currNode = this.head;
    let strList = [];
    while (currNode.next) {
      strList.push(JSON.stringify(currNode.element));
      currNode = currNode.next;
    }
    strList.push(JSON.stringify(currNode.element));
    return strList.join('->')
  }
}


let ming = { name: '小明', score: 100 },
  hongs = { name: '小红', score: 88 },
  jun = { name: '小军', score: 66 },
  li = { name: '小李', score: 50 };

let nList = new NodeList(ming);

nList.insertInNext(hongs);
nList.insertInNext(li);
nList.insertInNext(jun, hongs);

console.log('' + nList + '\n');

nList.remove(hongs);

console.log('' + nList + '\n');