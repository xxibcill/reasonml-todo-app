module Styles = {
  open Css;

  let fontSize = size => style([fontSize(`px(size))]);
  let fontColor = color_ => style([color(color_)]);

  let marginRight = mr => style([marginRight(`px(mr))]);
};

[@react.component]
let make = (~name, ~color=Colors.gray, ~size=12, ~marginRight=0) => {
  <i
    className={Css.merge([
      name,
      Styles.fontColor(color),
      Styles.fontSize(size),
      Styles.marginRight(marginRight),
    ])}
  />;
};
