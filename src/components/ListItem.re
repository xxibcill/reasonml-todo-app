open Types

module Styles = {
    open Css;

    let listContainer = style([
        display(`flex),
        justifyContent(`spaceBetween),
        alignItems(`center),
        padding2(~v=`px(5), ~h=`px(15)),
    ]);

    let checkbox = style([
        width(`px(20)), 
        height(`px(20)),
        margin4(~top=`zero, ~bottom=`zero,~left=`zero,~right=`px(15)),
    ])

    let indexNumber = style([
        margin4(~top=`zero, ~bottom=`zero,~left=`zero,~right=`px(10)),
    ])

    let label = style([
        width(`percent(70.)), 
    ])

    let editInput = style([
        width(`percent(90.)), 
    ])
};

[@react.component]
let make = (~data:todo,~index:int) => {
    let (_, dispatchTodos) = React.useContext(TodosContext.context);
    let (isEdit, setIsEdit) = React.useState(_ => false);
    let (text, setText) = React.useState(_ => data.text);
    let handleDelete = (_) => {
        dispatchTodos(DEL(index))
    };
    let handleSubmit = (event) => {
        ReactEvent.Form.preventDefault(event)
        if(text |> String.length > 0) {
            dispatchTodos(
                EDIT(
                    index,
                    {
                        isActive: data.isActive,
                        text: text
                    }
            ));
            setIsEdit(_ => false)
        }
    };

    <div className=Styles.listContainer> 
        <input className=Styles.checkbox type_="checkbox" name=text value=text/>
        <h3 className=Styles.indexNumber >{index + 1 |> Belt.Int.toString |> str => str ++ "." |> React.string}</h3>
        {isEdit ? 
            <form className=Styles.label onSubmit={handleSubmit} >
                <input
                    type_="text"
                    value=text
                    className=Styles.editInput
                    onChange={event => {
                        let newVal = ReactEvent.Form.target(event)##value |> String.trim;
                        setText(_ => newVal);
                    }}
                /> 
            </form> : 
            <label className=Styles.label> { text |> React.string} </label>
        }
        <div onClick={_ => setIsEdit(_ => true)}> 
            <Icon name="fa fa-pencil" size=20 color=Colors.black />
        </div>
        <div onClick=handleDelete> 
            <Icon name="fa fa-trash" size=20 color=Colors.black />
        </div>
    </div>
}