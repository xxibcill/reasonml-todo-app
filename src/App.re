module Styles = {
    open Css;

    let root =
        style([
            display(`flex),
            justifyContent(`center),
            alignItems(`center),
            width(`vw(100.)), 
            height(`vh(100.)), 
            backgroundColor(Colors.primary),
            position(`relative)
        ]);

    let textField =
        style([
            width(`percent(80.)), 
            marginLeft(`px(15))
        ])

    let addTodosHeader = 
        style([
            margin2(~v=`px(15),~h=`px(15))
        ])
};

open Types

[@react.component]
let make = () => {
    let (todos, dispatchTodos) = React.useContext(TodosContext.context);
    let (currentText, setCurrentText) = React.useState(_ => "");

    let handleSubmit = (event) => {
        ReactEvent.Form.preventDefault(event)
        if(currentText |> String.length > 0) {
            dispatchTodos(ADD({
                    isActive: false,
                    text: currentText
                }));
            setCurrentText(_ => "");
        }
    };

    <div className=Styles.root>
        <Card>
            // { todos -> Belt.List.map((element,index) => <ListItem key=Belt.Int.toString(index) index data=element />) |> Array.of_list |> React.array}
            { todos |> Utils.mapListItem |> Array.of_list |> React.array}
            <h4 className=Styles.addTodosHeader >{"Add Todos" |> React.string}</h4>
            <form onSubmit={handleSubmit} >
                <input
                    type_="text"
                    className=Styles.textField
                    value=currentText
                    onChange={event => {
                        let newVal = ReactEvent.Form.target(event)##value |> String.trim;
                        setCurrentText(_ => newVal);
                    }}
                />
            </form>
        </Card>
    </div>;
}