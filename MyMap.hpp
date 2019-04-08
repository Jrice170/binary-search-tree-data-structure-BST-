

#include "MyMap.h"


/// MyMap defult constructor

void get_identity(std::string & my_id)
{

  my_id = "jmr3by";

}


template <typename K, typename V>
MyMap<K, V>::MyMap()
{

    root = nullptr;

}
template <typename K, typename V>
MyMap<K, V>::MyMap(const MyMap<K, V> & source)
{
    if(source.root != nullptr)
    {
       TreeNode<MyPair<K, V>> * Fake_node;
       Fake_node = clone(source.root);
       root = Fake_node;

    }


}
template <typename K, typename V>
MyMap<K, V> & MyMap<K,V>::operator=(const MyMap<K, V> & source)
{

    if(source.root != nullptr)
    {

      TreeNode<MyPair<K, V>> * Fake_node;
      Fake_node = clone(source.root);
      root = Fake_node;
      return *this;

    }


}
template <typename K, typename V>
MyMap<K, V>::~MyMap()
{

  clear();

}
template <typename K, typename V>
V & MyMap<K, V>::at(const K &key)
{

    if(count(key)==0 || size() ==0)
    {

      throw std::out_of_range("Out of Range");


    }
    else
    {


        return at_helper(root,key);


    }



}
template <typename K, typename V>
V & MyMap<K,V>::operator[](const K & key)
{

  if(count(key) != 0)
  {
    return at_helper(root,key);
  }
  else
  {

      insert(MyPair<K,V>(key));
      return at_helper(root,key);

  }

}
template <typename K, typename V>
bool MyMap<K,V>::empty() const
{

    return size() == 0;


}
template <typename K, typename V>
int MyMap<K,V>::size() const
{

    return size_helper(root); // start at root travers and count

}
template <typename K, typename V>
void MyMap<K,V>::clear()
{


    clear_helper(root);

}
template <typename K, typename V>
void MyMap<K,V>::insert(const MyPair<K, V> &init_pair)
{

    K key = init_pair.first;
    if(count(key)>0)
    {
        at(key) = init_pair.second;


    }
    else
    {

      insert_helper(root,init_pair);


    }




}
template <typename K, typename V>
void MyMap<K, V>::erase(const K &key)
{

      erase_helper(root,key);


}
template <typename K, typename V>
MyPair<K, V> * MyMap<K,V>::find(const K & key)const
{


    return find_helper(root,key);


}
template <typename K, typename V>
void MyMap<K,V>::print()const
{


    print_helper(root," ");


}
template <typename K, typename V>
int MyMap<K, V>::count(const K &key)const
{


    return count_helper(root,key);

}
template <typename K, typename V>
V & MyMap<K,V>::at_helper(TreeNode<MyPair<K, V>> *&rt, const K &key)
{

  TreeNode<MyPair<K,V>> * pointer = rt;
  /// parse through the BST
  while(1)
  {

      if(key < pointer->data.first)
      {
          pointer = pointer->left;

      }
      else if(key > pointer->data.first)
      {
          pointer = pointer->right;

      }
      else if(key == pointer->data.first)
      {
          // returns the value
          return pointer->data.second;

      }
      else
      {
          break;

      }



  }


}
template <typename K, typename V>
int MyMap<K,V>::size_helper(TreeNode<MyPair<K, V>> * rt)const
{

    if(rt == nullptr)
    {

          return 0;

    }
    else
    {


        return size_helper(rt->left) + size_helper(rt->right) + 1;
    }




}
template <typename K, typename V>
void MyMap<K, V>::clear_helper(TreeNode<MyPair<K, V>> *& rt)
{

    /// post ourder delete
    if (rt != nullptr)
    {

        clear_helper(rt->left);

        clear_helper(rt->right);

        delete rt;

        rt=nullptr;


    }



}
template <typename K, typename V>
void MyMap<K, V>::insert_helper(TreeNode<MyPair<K, V>> *& rt,const MyPair<K, V> &init_pair)
{
        // starting root node
        // init pair
        if(rt == nullptr)
        {
          rt = new TreeNode<MyPair<K,V>>(init_pair,nullptr,nullptr);

        }
        else if(init_pair.first < rt->data.first)
        {

            insert_helper(rt->left,init_pair);

        }
        else
        {

            insert_helper(rt->right,init_pair);


        }


}
template <typename K, typename V>
TreeNode<MyPair<K, V>>* MyMap<K, V>::get_min(TreeNode<MyPair<K, V>> * rt)
{
    TreeNode<MyPair<K, V>> * Pointer = rt;


    while(Pointer->left != nullptr)
      Pointer = Pointer->left;

    return Pointer;



}
template <typename K, typename V>
void MyMap<K, V>::erase_helper(TreeNode<MyPair<K, V>> *&rt, const K &key)
{


  if(count(key) > 0 && rt != nullptr)
  {
      bool loop_on= true;
      bool right;
      bool left;
      TreeNode<MyPair<K,V>> * pointer = rt;
      TreeNode<MyPair<K,V>> * pre;
      if (key == root->data.first)  // key is equal to root nod then call special case
      {
          loop_on = false;
          TreeNode<MyPair<K, V>> * delptr = root;
          // root with 0 children
          if(root->left == nullptr && root->right == nullptr)
          {
              //clear();

              root = nullptr;
              delete delptr;


          }
          /// case one child
          else if(root->left == nullptr && root->right != nullptr)
          {

              root = root->right;
              delptr->right = nullptr;
              delete delptr;


          }
          else if(root->left != nullptr && root->right == nullptr)
          {
             root = root->left;
             delptr->left = nullptr;
             delete delptr;


          }
          // case 2
          else
          {

                TreeNode<MyPair<K,V>> * minvalue = get_min(root->right);
                auto first = minvalue->data.first;
                auto second = minvalue->data.second;
                erase(first); // delete the minvalue in tree;
                root->data.first = first;
                root->data.second = second;


          }



      }
      while(size() > 1 && loop_on)
      {

          if(key < pointer->data.first)
          {
              pre = pointer; /// base node it came from
              pointer = pointer->left;
              left = true;
              right = false;
          }
          else if(key > pointer->data.first)
          {
              pre = pointer; // base node it came from
              pointer = pointer->right;
              left = false;
              right = true;
          }
          else if(key == pointer->data.first)
          {

              // case 1 no children
              if(pointer->left == nullptr && pointer->right==nullptr)
              {
                if(left)
                {
                  pre->left = nullptr;
                  delete pointer;
                  pointer = nullptr;
                  break;

                }
                else if(right)
                {
                  pre->right = nullptr;
                  delete pointer;
                  pointer = nullptr;
                  break;

                }

              }
              // case 2 one child
              else if(pointer->left ==nullptr)
              {
                // move was left of base
                if(left)
                {     // good
                      pre->left = pointer->right;
                      delete pointer;
                      pointer = nullptr;
                      break;

                }
                else if(right)
                {
                      // good
                      pre->right = pointer->right;
                      delete pointer;
                      pointer = nullptr;
                      break;
                }

              }
              else if(pointer->right ==nullptr)
              {

                if(left)
                {
                      //good
                      pre->left = pointer->left;
                      delete pointer;
                      pointer = nullptr;
                      break;

                }
                else if(right)
                {     // good
                      pre->right = pointer->left;
                      delete pointer;
                      pointer = nullptr;
                      break;
                }



              }
              else
              {
                  TreeNode<MyPair<K, V>> * value_holder;



                  value_holder=get_min(pointer->right);
                  auto first = value_holder->data.first;
                  auto second = value_holder->data.second;
                  erase(value_holder->data.first);
                  pointer->data.first = first;
                  pointer->data.second = second;
                  break;




              }


              }



              }



          }


}
template <typename K, typename V>
MyPair<K, V> * MyMap<K,V>::find_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const
{

    if(rt == nullptr)
      return nullptr;

    if(key < rt->data.first)
    {
        return find_helper(rt->left,key);
    }
    else if(key > rt->data.first)
    {
        return find_helper(rt->right,key);

    }
    return &rt->data;

}
template <typename K, typename V>
void MyMap<K,V>::print_helper(TreeNode<MyPair<K, V>> *rt, std::string indent) const
{

    if(rt == nullptr)
    {
        cout<<indent<<"  [empty]"<<endl;
        return;

    }
    //cout<<rt->data.first<<endl;
    print_helper(rt->right,indent+=" ");

    cout<<indent<<"["<<rt->data.first<<"]="<<rt->data.second<<endl;

    print_helper(rt->left,indent);



}
template <typename K, typename V>
int MyMap<K,V>::count_helper(TreeNode<MyPair<K, V>> *rt, const K &key)const
{
    // base case
    if(rt == nullptr)
    {
        return 0;

    }
    if(rt->data.first <= key && rt->data.first>= key)
    {

        return 1 + count_helper(rt->right,key)+count_helper(rt->left,key);

    }
    else if(rt->data.first < key)
    {

      return count_helper(rt->right,key);

    }
    else return count_helper(rt->left,key);

}
template <typename K, typename V>
TreeNode<MyPair<K, V>> * MyMap<K,V>::clone(const TreeNode<MyPair<K, V>> *  rt)
{


    if(rt == nullptr)
    {

      return nullptr;
    }
    TreeNode<MyPair<K,V>> * pointer =\
    new TreeNode<MyPair<K,V>>(rt->data,nullptr,nullptr);
    pointer->left = clone(rt->left);
    pointer->right = clone(rt->right);
    return pointer;

}
void get_letter_frequency(MyMap<char, int> &in_tree)
{


}
