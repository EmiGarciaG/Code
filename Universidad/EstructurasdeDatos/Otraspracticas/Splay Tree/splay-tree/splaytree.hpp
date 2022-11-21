#ifndef __ED_SplayTree_HPP__
#define __ED_SplayTree_HPP__

#include <cassert>
#include <exception>
#include <functional>
#include <memory>
#include <iostream>

/** @brief a SplayTree's Node.*/
template <class T>
class SplayTNode
{
public:

    /** @brief Define a shared reference to a SplayTNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SplayTNode<T> > Ref;

    /** @name Life cicle.*/
    /** @{*/

    /** @brief Create a SplayTNode.
     * @post n_children() == 0
     */
    SplayTNode (T const& it=T(),
                SplayTNode<T>::Ref parent=nullptr,
                SplayTNode<T>::Ref left=nullptr,
                SplayTNode<T>::Ref right=nullptr):
        _item(it), parent_(parent), left_(left), right_(right)
    {}

    /** @brief Destroy a SplayTNode. **/
    ~SplayTNode()
    {}

    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    const T& item() const
    {
        return _item;
    }

    /** @brief Has it a parent?*/
    bool has_parent() const
    {
        return parent_ != nullptr;
    }

    /** @brief get the parent.*/
    const SplayTNode<T>::Ref& parent() const
    {
        return parent_;
    }

    /** @brief get the parent.*/
    SplayTNode<T>::Ref parent()
    {
        return parent_;
    }

    /** @brief Has it a left child?*/
    bool has_left() const
    {
        return left_ != nullptr;
    }

    /** @brief get the left child.*/
    const SplayTNode<T>::Ref& left() const
    {
        return left_;
    }

    /** @brief get the left child.*/
    SplayTNode<T>::Ref left()
    {
        return left_;
    }

    /** @brief Has it a right child? */
    bool has_right() const
    {
        return right_ != nullptr;
    }

    /** @brief get the right child.*/
    const SplayTNode<T>::Ref& right() const
    {
        return right_;
    }

    /** @brief get the right child.*/
    SplayTNode<T>::Ref right()
    {
        return right_;
    }

    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.*/
    void set_item(const T& new_it)
    {
        _item = new_it;
    }

    /** @brief Set the parent.*/
    void set_parent(SplayTNode<T>::Ref const& new_parent)
    {
        parent_ = new_parent;
    }

    /** @brief Remove link to the left child. */
    void remove_parent()
    {
        parent_.reset();
    }

    /** @brief Set the left child.*/
    void set_left(SplayTNode<T>::Ref const& new_child)
    {
        left_ = new_child;
    }

    /** @brief Remove link to the left child. */
    void remove_left()
    {
        left_.reset();
    }

    /** @brief Set the right child.*/
    void set_right(SplayTNode<T>::Ref const& new_child)
    {
        right_ = new_child;
    }

    /** @brief Remove link to the right child. */
    void remove_right()
    {
        right_.reset();
    }

protected:
    T _item;
    SplayTNode<T>::Ref parent_;
    SplayTNode<T>::Ref left_;
    SplayTNode<T>::Ref right_;
};

/**
 * @brief ADT SplayTree.
 * Models a SplayTree of T.
 */
template<class T>
class SplayTree
{
  public:

  /** @name Life cicle.*/
  /** @{*/

    /** @brief Create an empty SplayTree.
     * @post is_empty()
     */
    SplayTree ():
        root_(nullptr), current_(nullptr), parent_(nullptr)
    {}

    /** @brief Create a SplayTree using a given node as root.*/
    SplayTree (typename SplayTNode<T>::Ref& new_root):
        root_(new_root), current_(nullptr), parent_(nullptr)
    {}

    /** @brief Destroy a SplayTree.**/
    ~SplayTree()
    {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
      return root_ == nullptr;
  }

  /** @brief Get the root item.
   * @pre not is_empty();
   */
  T const& item() const
  {
      return root_->item();
  }

  /** @brief Get the root node.*/
  typename SplayTNode<T>::Ref const& root() const
  {
      return root_;
  }

  /** @brief Get the root node.*/
  typename SplayTNode<T>::Ref& root()
  {
      return root_;
  }

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /** @brief Set a new root node.
   * @pre new_root != nullptr
   * @post not is_empty()
   */
  void set_root(typename SplayTNode<T>::Ref& new_root)
  {
      assert(new_root!=nullptr);
      root_ = new_root;
      assert(is_a_binary_search_subtree(root_));
      assert(!is_empty());
  }

  /** @brief Remove the link to the root node
   * @post is_empty()
   */
  void remove_root()
  {
      root_.reset();
      assert(is_empty());
  }

  /**
   * @brief set the roor's item.
   * the new value do not change the ordering.
   * @pre not is_empty()
   * @pre item()==new_it
   */
  void set_item(const T& new_it)
  {
      assert(!is_empty());
      assert(item()==new_it);
      root_->set_item(new_it);
  }

  /**
   * @brief Search a key and promote to root.
   * @post retV implies item()==k
   */
  bool search(T const& k)
  {
      //check invariants.
      assert(is_a_binary_search_subtree(root_));

      bool found = false;

      //TODO: (using find())
      //If found, the current_ will be splaied.
      //if not found, parent_ will be splaid.



      //check invariants.
      assert(is_a_binary_search_subtree(root_));

      //check postconditions.
      assert(!found || item()==k);

      return found;
  }

  /**
   * @brief Insert a new key in the tree and promote to the root.
   * @warning if k is already in the tree, only it is updated.
   * @post item()==k
   */
  void insert(T const& k)
  {
      //check invariants.
      assert(is_a_binary_search_subtree(root_));

      //TODO: (using find())
      //First, find the key.
      //Second: if it was found, reset the k value.
      //Second: if not found, insert a new node as child of parent_. Update current_.
      //Third: splay current_


      //check invariants.
      assert(is_a_binary_search_subtree(root_));

      //check postconditions.
      assert(item()==k);
  }

  /**
   * @brief remove a value.
   */
  void remove (const T& k)
  {
      //check invariants.
      assert(is_a_binary_search_subtree(root_));

      //TODO: (using find())
      //First:  Find k.
      //Second: if found, remove current_ as in BST (using remove_bst()).
      //Third: splay the parent_.


      //check invariants.
      assert(is_a_binary_search_subtree(root_));
  }

  /** @}*/

private:

  /** @brief desactivate Copy constructor. */
  SplayTree(const SplayTree<T>& other);

  /** @brief desactivate assign operator. */
  SplayTree<T>& operator =(const SplayTree<T>& other);

protected:

  /**
   * @brief find a node with a key value moving the cursor.
   * @param k is the key to be found out.
   * @return true if it was found.
   */
  bool find(T const& k)
  {
      bool found = false;            
      parent_ = nullptr;
      current_ = root_;

      //TODO: Move cursor descending throw the tree.

    return found;
  }

  /**
   * @brief remove a node fo a BS tree.
   * @pre current_ != nullptr
   */
  void remove_bst ()
  {

      //check preconditions.
      assert(current_!=nullptr);

      bool replace_with_subtree = true;
      typename SplayTNode<T>::Ref subtree = nullptr;

      //TODO:
      //Adapt the code from remove method of BST
      //remembering to update the parent link for the subtree's root
      //used to replace the node to be removed for cases 0, 1, and 2.
      //parent_ must link to the parent of the removed node.

  }

  /**
   * @brief find the sucessor in order of current.
   */
  void find_inorder_sucessor()
  {
     parent_=current_;
     current_=current_->right();

     //TODO: descending throw the tree searching the inorder sucessor.

  }

  /**
   * @brief rotate x to right.
   *             |                |
   *             x                b
   *           /   \            /   \
   *         a       b         x     d
   *               /  \       / \
   *              c     d    a   c
   * @param x is the node to rotate.
   */
  void rotate_right(typename SplayTNode<T>::Ref x)
  {
      //TODO: you can adapt the code from: https://en.wikipedia.org/wiki/Splay_tree
  }

  /**
   * @brief rotate x to left.
   *           |         |
   *           x         a
   *          / \       / \
   *         a   b     c   x
   *        / \           / \
   *       c   d         d   b
   * @param x is the node to rotate.
   */
  void rotate_left(typename SplayTNode<T>::Ref x)
  {
      //TODO: you can adapt the code from: https://en.wikipedia.org/wiki/Splay_tree
  }

  /**
   * @brief splay a nodo to the root.
   * @param x is the node to promote.
   */
  void splay(typename SplayTNode<T>::Ref x)
  {
      //TODO: you can adapt the code from: https://en.wikipedia.org/wiki/Splay_tree
  }

  /**
   * @brief Check the binary search tree invariant.
   * @param node is the subtree's root.
   * @return true of the subtree with node as root is a binary search tree.
   */
  bool is_a_binary_search_subtree(typename SplayTNode<T>::Ref node)
  {
      bool is_bst = true;
      if (node)
      {
        is_bst = !node->has_left() || is_a_binary_search_subtree(node->left());
        is_bst = is_bst && (!node->has_left() || (node->left()->item() < node->item()));
        is_bst = is_bst && (!node->has_right() || (node->item()< node->right()->item()));
        is_bst = is_bst && (!node->has_right() || is_a_binary_search_subtree(node->right()));
      }
      return is_bst;
  }

  typename SplayTNode<T>::Ref root_;
  typename SplayTNode<T>::Ref current_;
  typename SplayTNode<T>::Ref parent_;

};

/**  @brief Fold an Splay tree node.
 * The output format will be:
 * [<item> : <left> : <right>] or [] if its a empty node.
*/
template<class T>
std::ostream&
fold_SplayTNode (std::ostream& out, typename SplayTNode<T>::Ref const& node)
{
    out << '[';
    if (node != nullptr)
    {
        out << node->item() << " : ";
        fold_SplayTNode<T>(out, node->left());
        out << " : ";
        fold_SplayTNode<T>(out, node->right());
    }
    out << ']';
    return out;
}

/**  @brief Fold an Splay tree. */
template<class T>
std::ostream&
operator << ( std::ostream& out, SplayTree<T> const& tree)
{
    fold_SplayTNode<T> (out, tree.root());
    return out;
}

/** @brief Load an SplayTNode from a input stream.
 * @return the node on success.
 * @warning runtime_error will throw if worng input format is found.
 */
template<class T>
std::istream&
operator >> (std::istream& in, typename SplayTNode<T>::Ref& node) noexcept(false)
{
    char sep=' ';
    while(in && sep!='[')
        in >> sep;
    if (!in)
        throw std::runtime_error("Wrong input format.");
    sep = static_cast<char>(in.peek());
    if (sep != ']')
    {
        T item;
        in >> item;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        while(in && sep!=':')
            in >> sep;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        typename SplayTNode<T>::Ref left;
        in >> left;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        while(in && sep!=':')
            in >> sep;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        typename SplayTNode<T>::Ref right;
        in >> right;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        node = std::make_shared< SplayTNode<T> >(item, left, right);
    }
    else
        in >> sep;//remove the close bracket from stream.
    return in;
}

/** @brief Load an Splay tree from a input stream.
 * @warning runtime_error will throw if worng input format is found.
 */
template<class T>
std::istream&
operator >> (std::istream& in, SplayTree<T>& tree)
{
    typename SplayTNode<T>::Ref root;
    in >> root;
    if (in)
        tree.set_root(root);
    return in;
}

#endif
