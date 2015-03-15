function testFunc()

	Engine.printMessage("testFunc begin")
	
	print("123")

	en = Engine.createEntity()
	Engine.CComponentsCollection col = en:collection()
	col:getComponent(1)
	
	Engine.printMessage("testFunc end1")

end