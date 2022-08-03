open Types

let slice = (list, i, k) => {

  let rec drop = (n, list) =>
    switch (list) {
    | [] => []
    | [_, ...xs] as z => n == 0 ? z : drop(n - 1, xs)
    };

  let rec take = (n, list) =>
    switch (list) {
    | [] => []
    | [x, ...xs] => n == 0 ? [] : [x, ...take(n - 1, xs)]
    };

  take(k - i + 1, drop(i, list));
};

type action = ADD(todo) | TOGGLE(todo) | EDIT(int,todo) | DEL(int)

let reducer = state =>
    fun 
    | ADD(item) => state @ [item]
    | DEL(index) => slice(state,0,index-1) @ slice(state,index+1,List.length(state))
    | EDIT(index,newValue) => slice(state,0,index-1) @ [newValue] @ slice(state,index+1,List.length(state))

let context = React.createContext(ContextHelper.default: (list(todo), action => unit));

[@react.component]
let make = (~children) => {
  let (state, dispatch) = React.useReducer(reducer, []);

  React.createElement(
    React.Context.provider(context),
    {"value": (state, dispatch), "children": children},
  );
};