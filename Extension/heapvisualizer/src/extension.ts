// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {

	// Use the console to output diagnostic information (console.log) and errors (console.error)
	// This line of code will only be executed once when your extension is activated
	console.log('Congratulations, your extension "heapvisualizer" is now active!');

	// The command has been defined in the package.json file
	// Now provide the implementation of the command with registerCommand
	// The commandId parameter must match the command field in package.json
	let disposable = vscode.commands.registerCommand('heapvisualizer.helloWorld', () => {
		// The code you place here will be executed every time your command is executed

		// Display a message box to the user
		vscode.window.showInformationMessage('Hello que pedo');
	});

	context.subscriptions.push(
		vscode.commands.registerCommand('heapvisualizer.memoryManagment', () => {
		  // Create and show a new webview
		  const panel = vscode.window.createWebviewPanel(
			'memoryManagment', // Identifies the type of the webview. Used internally
			'Memory managment', // Title of the panel displayed to the user
			vscode.ViewColumn.One, // Editor column to show the new webview panel in.
			{

				enableScripts: true

			} // Webview options. More on these later.
		  );

		  panel.webview.html = getWebviewContent();

		})
	  );

	context.subscriptions.push(disposable);
}

function getWebviewContent() {
  return `<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Memory managment</title>

		<style>
		table, th, td {
			border: 1px solid black;
			text-align: left;
		}
		table#t01 {
			width: 100%;    
			background-color: #ffffff;
			color: black;
		}
		</style>
	</head>

	<body>

		<h2>Memory managment table</h2>

		<input type="button" value="Add" onclick="myFunction();"/>

		<table id="t01">
		<tr>
			<th>Data type</th>
			<th>Data value</th> 
			<th>Memory location</th>
			<th>References in GC</th>
		</tr>
		</table>

		<script src="scriptMemoryManagment.js"></script>

	</body>

</html>`;
}

// this method is called when your extension is deactivated
export function deactivate() {

	console.log('Congratulations, your extension "heapvisualizer" is now deactivate!');

}
