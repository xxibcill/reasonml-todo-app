open Types

type mapFn = (todo,int) => React.element;
let rec map = (l:list(todo),f:mapFn,~n=0,~ret=[]) => {
    switch(l){
        | [] => ret
        | [first, ...rest] => map(rest,f,~n=n+1,~ret=ret @ [f(first,n)])
    }
}

let mapListItem = (l) => {
    map(
        l,
        (element,index) => <ListItem key=Belt.Int.toString(index) index data=element />,
        ~n=0,
        ~ret=[]
    )
}