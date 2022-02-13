package com.wztlink1013.datastructure.java.linkedlist;

/**
 * fun：实现ArrayList和LinkedList的接口
 *
 */

public interface List<E> {
    static final int ELEMENT_NOT_FOUND = -1;

    /**
     * 元素的数量[抽象类中实现]
     * @return
     */
    int size();

    /**
     * 是否为空[抽象类中实现]
     * @return
     */
    boolean isEmpty();

    /**
     * 是否包含某个元素[抽象类中实现]
     * @param element
     * @return
     */
    boolean contains(E element);

    /**
     * 添加元素到尾部[抽象类中实现]
     * @param element
     */
    void add(E element);

    /**
     * 清除所有元素[实现类中实现]
     */
    void clear();

    /**
     * 获取index位置的元素[实现类中实现]
     * @param index
     * @return
     */
    E get(int index);

    /**
     * 设置index位置的元素[实现类中实现]
     * @param index
     * @param element
     * @return 原来的元素ֵ
     */
    E set(int index, E element);

    /**
     * 在index位置插入一个元素[实现类中实现]
     * @param index
     * @param element
     */
    void add(int index, E element);

    /**
     * 删除index位置的元素[实现类中实现]
     * @param index
     * @return
     */
    E remove(int index);

    /**
     * 查看元素的索引[实现类中实现]
     * @param element
     * @return
     */
    int indexOf(E element);
}
