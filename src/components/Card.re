module Styles = {
  open Css;

  let container =
    style([
        width(`px(450)), 
        height(`px(650)), 
        overflow(`scroll),
        backgroundColor(Colors.white),
        padding(`px(10)),
        border(`px(1), `solid, Colors.black),
    ]);};

[@react.component]
let make = (~children) => {
    <div className=Styles.container >
        children
    </div>
}