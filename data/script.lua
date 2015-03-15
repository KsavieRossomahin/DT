function testFunc()

	Engine.printMessage("testFunc begin")

	en = Engine.createEntity()
	Engine.destroyEntity(en)
	--col = en:collection()
	--size = col:size()
	--print("size", size)

	Engine.printMessage("testFunc end")

end