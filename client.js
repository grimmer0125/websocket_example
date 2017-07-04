const WebSocket = require('ws');


var address ="ws:" + "//localhost" + ":3003";


// const ws = new WebSocket('ws://www.host.com/path');

const ws = new WebSocket(address);

ws.on('open', function open() {
  ws.send('something');
});

ws.on('message', function incoming(data) {
  console.log("get message from server")
  console.log(data);
});
