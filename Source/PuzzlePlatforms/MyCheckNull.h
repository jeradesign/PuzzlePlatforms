#pragma once
#define MYCHECKNULL(__pointer_to_check__) do { if (__pointer_to_check__ == nullptr) { \
	UE_LOG(LogTemp, Error, TEXT("null pointer: " #__pointer_to_check__));\
	} } while (false)
