module Styles = {
  open Css;

  let list =
    style([
      padding2(~v=`px(15), ~h=`px(15)),
    ]);
};

[@react.component]
let make = (~name) => {
    <div className=Styles.list>
        <input type_="text" name/>
        <label> { name |> React.string} </label>
    </div>
}