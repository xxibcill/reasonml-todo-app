// Entry point
[@bs.val] external document: Js.t({..}) = "document";
let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= AppStyle.style;

// render to DOM
ReactDOMRe.render(
  <TodosContext><App/></TodosContext>,
    
  document##getElementById("root"),
);

