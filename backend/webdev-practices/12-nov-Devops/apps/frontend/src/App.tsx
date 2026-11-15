import { useState } from "react";
import ImagePreview from "./components/ImagePreview"
import UploadImage from "./components/UploadImage";

function App() {

  const [previewUrl, setPreviewUrl] = useState<string | null>(null);

  return (
    <>
      <UploadImage onUploadSuccess={setPreviewUrl}/>
      <ImagePreview PreviewUrl={ previewUrl } />
    </>
  );
}

export default App
