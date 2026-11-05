pragma solidity ^0.8.20;

contract BankAccount {
    mapping(address => uint) public balances;

    function deposit() public payable {
        require(msg.value > 0, "Amount must be greater than zero");

        balances[msg.sender] += msg.value;
    }

    function withdraw(uint amount) public {
        require(amount > 0, "Amount must be greater than zero");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        balances[msg.sender] -= amount;

        payable(msg.sender).transfer(amount);
    }

    function getBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}