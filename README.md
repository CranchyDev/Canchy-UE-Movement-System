# Canchy-UE-Movement-System
Cranchy UE (Unreal Engine) Movement System, is a simplistic and quick way of introducing movement through a 'Copy &amp; Paste' fashion, making it ideal for any new projects that are being built from scratch.

<h2>Instructions to help you setup the code in your project</h2>

Copy and paste the code within these classes towards newly created ones.

Don't forget to change names in accordance to the name of the project.

----------

>>>>> Before you proceed with copy pasting the code, make sure to create a Project that is C++.

<b>NOTE: The name of the Project should be different, but be aware that some of the code must be adapted to that.</b>

----------

<h3><b>Then create each C++ class within the Editor with these optional names or whichever names you prefer:</b></h3>

MainChar -> <b>(Character Class)</b>

MainPController -> <b>(Player Controller Class)</b>

PController_MainChar_Interface -> <b>(Unreal Interface Class)</b>

>>> The Name of the project within this code may differ from yours and <b>YOU HAVE TO CHANGE</b> within the newly created classes. <<<
>> Change the title of the API at the beginning of each class after Copy + Pasting the code
>>> 
> Example: class CRANCHY_MOVEMENTSYS_API IIamAnInterface <- (CRANCHY_MOVEMENTSYS_API should be instead NAMEOFYOURPROJECT_API)
{
	GENERATED_BODY()
	...
};

----------

<h3><b>Then create these Blueprint Classes:</b></h3>

<b>Specifically, edit these Input Actions to be setup as either a Bool/2DAxis:</b>

<img width="800" height="25" alt="image" src="https://github.com/user-attachments/assets/51baa97f-c015-4a75-a2dc-a78e6c443334" />
<img width="799" height="26" alt="image" src="https://github.com/user-attachments/assets/5c09d7bb-d13d-4533-aef6-79decdaba185" />

<b>IA_CameraRotation</b> (Axis2D(Vector2D))

<b>IA_Crouch</b> (Bool)

<b>IA_Jump</b> (Bool)

<b>IA_Move</b> (Axis2D(Vector2D))

<b>IA_Sprint</b> (Bool)

<br>

<b>Then continue creating the following Blueprint Classes:</b>

<b>MainInputMappingContext</b> <- IMC (Input Mapping Context) (we'll also use this one later to setup peripheral inputs)

<b>UserInterfaceInputMappingContext</b> <- Another IMC but to be used for UI for later usage <b>(highly optional)</b>

<b>MyMainCharBP</b> <- This MUST be derived from the MainChar.cpp class

<b>MyMainPControllerBP</b> <- This MUST be derived from the MainPController.cpp class

-----------

<h3><b>Make sure you do these:</b></h3>

-> Within MyMainPControllerBP <- <b>You must select two IMC's for each one of the slots, and also for each IA (Input Action).</b>

<img width="1343" height="749" alt="image" src="https://github.com/user-attachments/assets/a62bd9a4-fe18-4555-9ef0-c21154e174b7" />

-> Within MainInputMapping Context <- <b>Perform this setup on the IA_MoveKeyboard:</b>

-> <b>S(Walking Backwards)</b>  -> Add Modifiers -> Negate
<br>
-> <b>A (Walking Left</b> ) -> Add Modifiers -> Swizzle Input Axis Values and Negate
<br>
-> <b>D (Walking Right)</b>  -> Add Modifiers -> Swizzle Input Axis Values

-> Lastly, still within MainInputMapping Context <- <b>Perform this quick setup on the IA_CameraRotation -> Modifiers -> Negate</b>

>>NOTE: When you add Negate, it automatically checks the XYZ. Make sure only Y is checked.

<img width="1287" height="1047" alt="image" src="https://github.com/user-attachments/assets/1b50d165-b780-412a-a49d-8b3eb4e65c5c" />

-> <b>Check names if something isn't working!</b> 

-> <b>On MyMainCharBP <- Change 'Use Pawn Control Rotation' to True</b>, if it isn't already. Otherwise, your camera won't turn up and down.

>>
-----------
