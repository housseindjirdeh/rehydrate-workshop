module Page = {
  module GroupCounter = {
    include ReactRe.Component.Stateful;
    let name = "GroupCounter";
    type state = {count: int};
    type props = unit;
    let getInitialState props => {count: 0};
    let componentDidMount {state} => {
      ReasonJs.setInterval (fun () => Js.log "beep") 500;
      None
    };
    /* increment handler */
    let handleIncrement {state} event => {
      Js.log "clicked increment!";
      Some {count: state.count + 1}
    };
    /* decrement handler */
    let handleDecrement {state} event => {
      Js.log "clicked decrement!";
      Some {count: state.count - 1}
    };
    let render {props, state, updater} =>
      <div>
        <h1> (ReactRe.stringToElement (string_of_int state.count)) </h1>
        <button onClick=(updater handleIncrement)> (ReactRe.stringToElement "Increment") </button>
        <button onClick=(updater handleDecrement)> (ReactRe.stringToElement "Decrement") </button>
      </div>;
  };
  include ReactRe.CreateComponent GroupCounter;
  let createElement = wrapProps ();
};

let () = ReactDOMRe.render <Page /> (ReasonJs.Document.getElementById "index");
